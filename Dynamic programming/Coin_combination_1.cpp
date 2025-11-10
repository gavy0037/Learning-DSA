/*
Consider a money system consisting of n coins. Each coin has a positive integer value.
Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.

For example, if the coins are {2, 3, 5} and the desired sum is 9, there are 8 ways:
2 + 2 + 5
2 + 5 + 2
5 + 2 + 2
3 + 3 + 3
2 + 2 + 2 + 3
2 + 2 + 3 + 2
2 + 3 + 2 + 2
3 + 2 + 2 + 2

Input

The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c₁, c₂, …, cₙ: the value of each coin.

Output
Print one integer: the number of ways modulo 10⁹ + 7.

*/

// *************** RECURSIVE DP IN C *****************

// #include<stdio.h>
 
// #define MOD (int)1e9+7
 
// int help(int n , int arr[] , int x , int sum , int dp[]){
//     if(sum == x) return 1 ;
//     else if(sum > x) return 0 ;
    
//     if(dp[sum] != -1) return dp[sum];
    
//     int ans = 0;
//     for(int i = 0 ; i < n ; i++){
//         ans += help(n , arr , x , sum+arr[i] , dp);
//         ans%= MOD ;
//     }
 
//     return dp[sum] = ans ;
// }
 
// int main(){
//     int n , x ;
//     scanf("%d %d",&n,&x);
//     int arr[n] , dp[x+1];
//     for(int i = 0 ; i < n ; i++) scanf("%d" , &arr[i]);
    
//     for(int i = 0 ; i <= x ; i++) dp[i] = -1 ;
 
//     printf("%d\n",help(n , arr , x, 0 , dp));
 
//     return 0 ;
// }


#include <iostream>
#include <vector>
using namespace std;
const int M = 1000000007;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int j = 0; j < n; ++j) {
        cin >> c[j];
    }

    vector<int> ways(x + 1);
    ways[0] = 1;
    for (int i = 1; i <= x; ++i) {
        ways[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (i - c[j] >= 0) {
                ways[i] = (ways[i] + ways[i - c[j]]) % M;
            }
        }
    }

    cout << ways[x] << "\n";
}