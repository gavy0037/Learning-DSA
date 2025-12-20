#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include<algorithm>

using namespace std ;

void print(vector<int>nums){
    for(int i = 0 ; i < nums.size() ; i++) cout<<nums[i]<<' ';

    cout<<endl ;
}

int largestRectangleArea(vector<int>& heights) {
    //we can use the approach to get the largest possible rectangle for any given height
    // for this we will use the left smaller and right smaller elements as they are the ones that are gonna
    // stop our expansion of rectangle
    // first we calculate right smaller and left smaller elements

    int h = heights.size();
    vector<int> left_smaller(h , -1) , right_smaller(h , -1);
    stack<int>stk ;
    for(int i =  0 ; i < h ; i++){ // for left_smaller elements
        while(stk.size()>0 && heights[stk.top()] >= heights[i]) stk.pop();

        if(stk.size() != 0) left_smaller[i] = stk.top();

        stk.push(i);
    }

    while(stk.size()>0) stk.pop();
    for(int i = h-1 ; i >=0 ; i--){
        while(stk.size() > 0 && heights[stk.top()] >= heights[i]) stk.pop();

        if(stk.size() != 0) right_smaller[i] = stk.top();

        stk.push(i);
    }

    int ans = INT_MIN ;
    for(int i = 0;  i < h ; i++){
        int right = right_smaller[i], left = left_smaller[i];
        if(right == -1) right = h ;
        if(left == -1) left = -1 ;
        ans = max(ans , heights[i] * (right-left-1));
    }

    return ans ;
}

int main(){
    vector<int>nums = {1,1};
    cout<<largestRectangleArea(nums);
}



