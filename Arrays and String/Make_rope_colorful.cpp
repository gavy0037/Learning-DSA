/*
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help.
Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) 
that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std ;

int minCost(string s, vector<int>& nums) {
        int ans = 0 , st=0 , end=0 ; 
        int i = 0 ; 
        while(i <s.length()){
            if(i && s[i] == s[i-1]){
                end++;
            }else if(i && s[i] != s[i-1]){
                if(st<end){
                    //use loop to get the min time
                    int maxe = 0 ;
                    for(int i = st ; i <= end ; i++){
                        maxe = max(maxe,nums[i]);
                    }
                    for(int i = st ; i <= end ; i++){
                        ans+=(nums[i]);
                    }
                    ans-=maxe ;//do not include the maximum element
                }
                st = end = i;
            }
            i++;
        }

        if(st<end){// to get the min time for the last consecutive subsequence
        int maxe = 0 ;
            for(int i = st ; i <= end ; i++){
                maxe = max(maxe,nums[i]);
            }
            for(int i = st ; i <= end ; i++){
                ans+=(nums[i]);
            }
            ans-=maxe ;
        }
        return ans ;
    }

int main(){
    vector<int>nums = {4,8,8,4,4,5,4,2};
    string s = "cddcdcae";
    cout<<minCost(s , nums);
}