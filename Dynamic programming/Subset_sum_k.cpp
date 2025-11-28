#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

    int isSubsetSum(vector<int> arr, int sum) {
        // code here
        int n = arr.size();
        vector<int>dp(sum+1 , 0);
        dp[0] = 1 ;
        sort(arr.begin() , arr.end());
        for(int j = 0 ; j < n ; j++){
            for(int i = sum ; i >=arr[j] ; i--){
                if(dp[i] == 0) dp[i] = dp[i-arr[j]];
            }
        }
        return dp[sum] ;
    }

int main(){
    cout<<isSubsetSum({51 ,41 ,6 ,16, 56, 46, 58, 46 ,19 ,1 ,47 ,31 ,5 ,58} ,383);

    return 0 ;
}