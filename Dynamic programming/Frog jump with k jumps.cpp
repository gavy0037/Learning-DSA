#include<iostream>
#include<vector>
#include<climits>

using namespace std ;
int abs(int a){
    return a < 0 ? -a : a ;  
}
int helper(int nums[] , int k ,int pos , int arr[]){
    if(pos == 0 ){
        return 0 ;
    }
    if(arr[pos] != -1) return arr[pos] ;

    int a = INT_MAX ;
    
    for(int i = 1 ; i <= k ; i++){
        if(pos-i < 0) break ;
        a = min(a , helper(nums , k , pos-i , arr) + abs(nums[pos]-nums[pos-i]));
    }

    return arr[pos] = a ;
}

int main(){
    int n ;
    cin>>n ;
    int nums[n];
    for(int i = 0 ;i < n ;i++){
        cin>>nums[i];
    }
    int arr[n] = {-1};//may not work on all machines so can use a loop to give all entries to -1
    //or use a vector and intitalize it like *****vector<int>arr(n,-1)*******

    helper(nums , 4 ,  4 , arr);
    cout<<arr[n-1];

    return 0 ;
}
