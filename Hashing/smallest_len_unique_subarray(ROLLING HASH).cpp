/*
You are given an integer array nums.

Find the minimum length of a subarray that is not identical to any other subarray in nums.

Return an integer denoting the minimum possible length of such a subarray.

Two subarrays are considered identical if they have the same length and the same elements in corresponding positions.
*/

#include<bits/stdc++.h>

using namespace std;

#define MOD1 1000000007
#define MOD2 998244353
#define BASE1 31
#define BASE2 37

class Solution {
public:
    // Returns true if there EXISTS at least one subarray of 
    // this length that has no duplicate
    bool hasUniqueSubarray(vector<int>& nums, int length) {
        long long HASH1 = 0, HASH2 = 0;
        long long pw1 = 1, pw2 = 1;

        for(int i = 0; i < length; i++){
            pw1 = pw1 * BASE1 % MOD1;
            pw2 = pw2 * BASE2 % MOD2;
        }
        unordered_map<long long, int> freq;

        for(int i = 0; i < length; i++){
            HASH1 = (HASH1 * BASE1 % MOD1 + nums[i]) % MOD1;
            HASH2 = (HASH2 * BASE2 % MOD2 + nums[i]) % MOD2;
        }

        long long key = HASH1 * MOD2 + HASH2;
        freq[key]++;

        for(int i = length; i < (int)nums.size(); i++){
            // slide window
            HASH1 = (HASH1 * BASE1 % MOD1 
                    - (long long)nums[i-length] * pw1 % MOD1 
                    + MOD1) % MOD1;
            HASH1 = (HASH1 + nums[i]) % MOD1;

            HASH2 = (HASH2 * BASE2 % MOD2 
                    - (long long)nums[i-length] * pw2 % MOD2 
                    + MOD2) % MOD2;
            HASH2 = (HASH2 + nums[i]) % MOD2;

            key = HASH1 * MOD2 + HASH2;
            freq[key]++;
        }

        // check if ANY subarray has frequency == 1 (no duplicate)
        for(auto& [k, cnt] : freq)
            if(cnt == 1) return true;

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int st = 1, end = nums.size();
        int ans = nums.size();

        while(st <= end){
            int mid = (st + end) / 2;
            if(hasUniqueSubarray(nums, mid)){
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};