#include<iostream>
#include<vector>
#include<climits>

using namespace std ;
int abs(int a){
    return a < 0 ? -a : a ;  
}
int Frog_jump_with_k_jumps(int nums[] , int k ,int pos , int arr[]){
    if(pos == 0 ){
        return 0 ;
    }
    if(arr[pos] != -1) return arr[pos] ;

    int a = INT_MAX ;
    
    for(int i = 1 ; i <= k ; i++){
        if(pos-i < 0) break ;
        a = min(a , Frog_jump_with_k_jumps(nums , k , pos-i , arr) + abs(nums[pos]-nums[pos-i]));
    }

    return arr[pos] = a ;
}

int main(){
    int n , k ;
    cin>>n>>k ;
    int nums[n];
    for(int i = 0 ;i < n ;i++){
        cin>>nums[i];
    }
    int arr[n] = {-1};//may not work on all machines so can use a loop to give all entries to -1
    //or use a vector and intitalize it like *****vector<int>arr(n,-1)*******

    int dp[n];
    dp[0] = 0 ;
    for(int i = 1 ; i<n ; i++){
        int min_energy_step = INT_MAX ;
        for(int j = 1 ; j <= k ; j++){
            if(i-j < 0 ) break ;
            min_energy_step = min(min_energy_step,dp[i-j] + abs(nums[i]-nums[i-j]));
        }

        dp[i] = min_energy_step ;
    }

    //cout<<dp[n-1] ;// IF USING THE BOTTOM UP APPROACH
    
    //if using the recursion method (it takes a O(n) extra stack space) call the function and the print arr[n-1]
    
    return 0 ;
}
