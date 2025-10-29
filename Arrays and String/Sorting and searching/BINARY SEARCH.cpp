#include<iostream>
#include<vector>

using namespace std ;

int binarysearch(vector<int>nums,int target){

    int st = 0 , end = nums.size()-1 ;
    while(st <= end ){
        int mid = st + (st-end)/2 ;//TO AVOID THE CASE OF INTMAX + INTMAX IN (st+end)/2  WE USE THIS FORMULA 

        if(target < nums[mid]){
            end = mid -1 ;
        }else if (target>nums[mid]){
            st = mid +1 ;
        }else{
            return mid ;
        }
    }
    return -1 ;
}
int main (){

vector<int>vec = {1,2,3,4,5,6,2,4,5,8,9} ;
int target = 9 ;
cout<<binarysearch(vec,target);
    return 0 ;
}