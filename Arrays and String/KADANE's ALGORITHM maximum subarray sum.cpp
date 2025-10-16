#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int kadanealgo(vector<int>nums){
    int currsum = 0 , maxsum = INT_MIN ;
    for(int i = 0 ; i < nums.size();i ++){
        currsum+=nums[i];
        maxsum = max(currsum,maxsum);
        if(currsum < 0){
            currsum = 0 ;
        }
    } 
    return maxsum;
}


int main (){
    vector<int>vec = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<kadanealgo(vec);

    return 0 ;
}

// int maxsubarry(vector<int>nums ){

//     int summax = -(INT_MAX);
// for(int st = 0 ; st < nums.size() ; st ++){
// int sum = 0 ;
//     for(int end = st ; end <= nums.size() ; end ++){

//        sum += nums[end];

//         if(sum > summax){
//             summax = sum ;
//         }
//     }
// }  
//     return summax ;
// }
