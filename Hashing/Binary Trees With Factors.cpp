/*                 

            LEETCODE 823

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std ;

#define MOD 1000000007

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin() , arr.end());

        map<long long,long long>mp ;
        long long ans = 0 ;
        for(int i = 0 ; i < arr.size() ; i++){
            // find a left child
            mp[arr[i]] = 1; // single node tree
            for(int j = 0 ; j < i ; j++){
                if(arr[i]%arr[j] == 0){
                    // a possible left child
                    // see if we have a right child

                    if(mp.find(arr[i]/arr[j]) != mp.end()){
                        mp[arr[i]] = (mp[arr[i]/arr[j]]*mp[arr[j]] + mp[arr[i]])%MOD;
                    }
                }
            }
            ans = (ans+mp[arr[i]])%MOD ;
            
        }

        return (int)ans ;
    }
};