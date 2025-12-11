#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

    int isSubsetSum1(vector<int> arr, int sum) {
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

    /******************* EASIER TO UNDERSTAND *********************/

    int isSubsetSum2(vector<int> arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>>dp(n , vector<bool>(sum+1 , -1));
        for(int i = 0 ; i < n ; i++) dp[i][0] = false ;
        if(arr[0] <= sum) dp[0][arr[0]] = true ;
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1; j <= sum ; j++){
                bool nottake = dp[i-1][j];

                bool take = false ;
                if(j-arr[i] >= 0) take = dp[i-1][j-arr[i]];

                dp[i][j] = take | nottake ;
            }
        }
        return dp[n-1][sum];
    }

int main(){
    cout<<isSubsetSum2({51 ,41 ,6 ,16, 56, 46, 58, 46 ,19 ,1 ,47 ,31 ,5 ,58} ,383);

    return 0 ;
}