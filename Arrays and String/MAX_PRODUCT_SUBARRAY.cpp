#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std ;

    int maxProduct(vector<int> &nums) {//grredy approach
        // code here
        int maxi = nums[0] , mini = nums[0];
        int ans = maxi ;
        for(int i = 1 ; i < nums.size() ; i++){ 
            int temp = max({nums[i],nums[i]*maxi,nums[i]*mini});
            mini = min({nums[i] , nums[i]*mini , nums[i]*maxi});
            maxi = temp ;
            ans = max(maxi,ans);
        }
        return ans ;
    }

    int maxProduct(vector<int> &nums) {//
        // code here
        int n = nums.size() ;
        int ans = INT_MIN ;
        
        int lr = 1 ,rl = 1 ;//products from leftToRight and RightToLeft
        for(int i = 0 ; i < nums.size() ; i++){
            if(lr == 0){//to start a new subarry after encountring a zero
                lr = 1 ;
            }if(rl == 0){
                rl = 1 ;
            }
            
            lr*=nums[i];
            rl*=nums[n-i-1];
            ans = max({ans , rl , lr});
        }
        return ans ;
    }