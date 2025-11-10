/*
Consider a money system consisting of n coins. Each coin has a positive integer value. 
Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.

For example, if the coins are {2, 3, 5} and the desired sum is 9, there are 3 ways:
2 + 2 + 5
3 + 3 + 3
2 + 2 + 2 + 3

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c₁, c₂, …, cₙ: the value of each coin.

Output
Print one integer: the number of ways modulo 10⁹ + 7
*/

/******************RECURSIVE DP IN C (but not memory favorable)******************** */

// int ways(int n , int arr[] , int x , int sum , int dp[][n] , int pos){
//     if(sum == x) return 1 ;
//     else if(sum > x) return 0 ;
    
//     if(dp[sum][pos] != -1) return dp[sum][pos];
    
//     int ans = 0;
//     for(int i = pos ; i < n ; i++){
//         ans += help(n , arr , x , sum+arr[i] , dp , i );
//         ans%= MOD ;
//     }

//     return dp[sum][pos] = ans ;
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
    for (int j = 0; j < n; ++j) {
        for (int i = c[j]; i <= x; ++i) {
            ways[i] = (ways[i - c[j]] + ways[i]) % M;
        }
    }

    cout << ways[x] << "\n";
}