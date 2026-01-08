#include<iostream>

using namespace std ;

class max_heap{
    public:
    int arr[100];
    int size ;

    // implemented using root indexed at 1
    max_heap(){
        arr[0] = -1 ;
        size = 0 ;
    }

    void insert(int val){
        int idx = ++size;// for 0 based it would be size++;
        arr[idx] = val ;
        while(idx > 1){
            int parent_idx = idx/2 ;// for 0 based indexing it would be idx-1 /2
            if(arr[idx] > arr[parent_idx]){
                swap(arr[idx] , arr[parent_idx]);
                idx = parent_idx ;
            }
            else break ;
        }
    }

    void deleteroot(){
        if(size == 0) return ;

        swap(arr[1] , arr[size]);
        size--;

        int i = 1 ;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
                largest = left;

            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    void print(){
        for(int i = 1 ; i < size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl ;
    }
};

void heapify(int arr[] , int size , int i){// needed to be called for each index starting from the n/2th node till 1 as fron n/2 +1 to n-1 indexes we will have leaf nodes that would be heap anyway .
    int largest = i ;
    int left = 2*i , right = 2*i+1 ;
    if(left < size && arr[largest] < arr[left]) largest = left ;
    if(right < size && arr[largest] < arr[right]) largest = right;
    
    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr , size , largest);
    }
}


void heap_sort(int heap[] , int size){// heap is max_heap here
    if(size == 1) return ;


    while(size > 1){
        swap(heap[1] , heap[size-1]);
        size--;
        heapify(heap , size-1 , 1);
    }
}

int main(){
    max_heap h1 ;
    h1.insert(51);
    h1.insert(52);
    h1.insert(53);
    h1.insert(54);
    h1.insert(55);

    h1.print();


    int arr[] = {-1,2,11,10,56,7,8,9};
    for(int i = 7/2 ; i >= 1 ; i--){
        heapify(arr , 8 , i);
    }

    heap_sort(arr , 8); // -> two steps to sort a heap first build a heap and then heap sort it

    for(auto i : arr){
        cout<<i<<" ";

    }

    
    cout<<endl ;
    return 0 ;
}