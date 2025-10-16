#include<stdio.h>

void PrintSubsetSumK(int n , int arr[] , int pos  , int temp[] , int size , int target){

        if(target == 0){
            printf("{");
            for(int i = 0 ; i < size ; i++){
                if(i != size-1){
                    printf("%d, ",temp[i]);
                }else{
                    printf("%d",temp[i]);
                    
                }
            }
            printf("}\n");
            return ;
        }
        if(pos == n) return ;

    for(int i = pos ; i < n ; i++){
        if(i>pos && arr[i] == arr[i-1]) continue ;

        if(target-arr[i] < 0) break  ; 
        temp[size] = arr[i];
        PrintSubsetSumK(n , arr , i+1 , temp , size+1 , target-arr[i]);
    }
}

void merge(int n , int arr[] , int st , int mid , int end){
    int i = st , j = mid+1 ;
    int temp[end-st+1] , idx = 0 ;
    while(i <= mid && j <= end){
        temp[idx++] = arr[i] < arr[j] ? arr[i++] : arr[j++] ;
    }

    while(i<=mid){
        temp[idx++] = arr[i++];
    }
    while(j<=end){
        temp[idx++] = arr[j++];
    }

    for(int i = 0 ; i < end-st+1 ; i++){
        arr[st+i] = temp[i];
    }
}

void merge_sort(int n , int arr[] , int st , int end){
    if(st<end){
        int mid = st+(end-st)/2 ;
        merge_sort(n , arr , st , mid);
        merge_sort(n , arr , mid+1 , end);

        merge(n , arr , st , mid , end);
    }
}


int main(){
    int n , k ;
    scanf("%d %d",&n , &k);
    int arr[n],temp[n];
    for(int i = 0 ; i < n ;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(n , arr , 0 , n-1);


    PrintSubsetSumK(n , arr , 0 , temp , 0 , k);

    return 0   ;
}