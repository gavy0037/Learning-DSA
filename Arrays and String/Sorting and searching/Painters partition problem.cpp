#include<iostream>
#include<vector>
using namespace std;

bool isvalid(int mintime , int n , int m, vector<int>nums){
    int painter = 1 , time = 0 ;
    for(int val : nums)
    if(time + val <= mintime){
        time+=val;

    }else{
        time = val;
        painter++;
    }
    return painter>m ? false : true;
}

int mintimeforpainting( int m, vector<int>nums ){
    int n = nums.size();
    int sum = 0 ;
    if(m>n){
        return -1 ;
    }
    for(int val : nums){
        sum+=val;
    }

    int st = 0 , end = sum , ans = -1;//CAN BE OPTIMIZED USING ST AS MAXIMUM VALUE IN NUMS
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isvalid(mid,n,m,nums)){
            ans = mid ;
            end = mid-1;
        }else{
            st = mid + 1 ;
        }
    }
    return ans ;
}





int main (){
vector<int>nums={10, 20, 30, 40, 50};
int m =3 ;
cout<<mintimeforpainting(m,nums);
    return 0;
}