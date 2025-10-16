#include<iostream>
#include<vector>
#include<climits>
using namespace std;


vector<int> bublesort(vector<int>nums){
    for(int i = 0 ; i < nums.size()-1; i++){

        bool isswap = false ;
        for(int j = 0 ; j<nums.size()-1 ; j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j+1],nums[j]);
                isswap = true ;
            }
        }
        if(isswap == false){
                break;
            }
    }
    return nums;
}

vector<int> selectionsort(vector<int>nums){
    for(int i = 0 ; i <nums.size()-1; i++){
        int minindex = i ;
        for(int j = i ; j<nums.size();j++){//ALSO CORRECT IF j IS INTIALIZED WITH i+1 
            if(nums[minindex]>nums[j]){
                minindex = j;
            }
        }
        swap(nums[minindex],nums[i]);
        }
        return nums ;   
    }

vector<int> insertionsort(vector<int>nums){

    for(int i = 1 ; i < nums.size() ; i++){
        int curr = nums[i];
        int prev = i-1;
        while(prev >=0 && curr<nums[prev]){
            nums[prev+1] = nums[prev];
            prev--;
        }
        nums[prev+1] = curr ;
}
return nums;
}


//mergesort starts
void merge(vector<int>&nums , int st , int mid, int end){
    vector<int>temp;
    int i = st , j = mid+1 ;//two pointers

    while(i<=mid && j<=end){//sorting and storing in temprory vector
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i<=mid){//remaining in left half
        temp.push_back(nums[i]);
            i++;
    }
    while (j<=end){//remaining in right half
        temp.push_back(nums[j]);
        j++;
    }

    for(int idx = 0 ; idx <temp.size() ; idx++){//doing changes in nums
        nums[st+idx] = temp[idx];
    }
    

}
void mergesort(vector<int>&nums , int st , int end)  {
    if(st<end){
        int mid = st + (end-st)/2; 
        mergesort(nums,st,mid);//left half
        mergesort(nums,mid+1,end);//right half
        merge(nums,st,mid,end);//merging right and left half

    }
}
//mergesort ends

//quicksort begins
int partition(vector<int> &nums , int st, int end){
    int idx = st-1 , pivot = nums[end];
    for(int j = st ; j < end ; j++){
        if(nums[j]<=pivot){
            idx ++ ;
            swap(nums[j],nums[idx]) ;
        }
    }
    idx++;
    swap(nums[idx],nums[end]) ;
    return idx ; 
}

void quicksort(vector<int> &nums,int st , int end){
    if(st<end){
        int pivotidx = partition(nums,st,end);

        quicksort(nums,st,pivotidx-1);//left half
        quicksort(nums,pivotidx+1,end);//right half
    }
}
//quicksort ends

int main(){
    vector<int>vec = {4,8,1,9};
    vector<int>nums ;
    nums = insertionsort(vec);
for(int i = 0 ; i <vec.size();i++){
    cout<<nums[i]<<" ";
}
}
