#include<iostream>
#include<vector>
using namespace std;

bool isvalid(int maxallowed , int m , int n , vector<int>nums){
    int pages= 0 , student = 1;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]> maxallowed){
            return false ;
        }
        if(pages+nums[i] <= maxallowed){
            pages +=nums[i];
        }else{
            student++;
            pages = nums[i];
        }
    }
    return student>m ? false : true ;
}

int bookallocation(int m , int n , vector<int>nums){

    if(m>n){
        return -1 ;
    }
    int sum = 0 ,ans = -1;
    for (int i = 0; i < n; i++)
    {
        sum+=nums[i];
    }
    int st = 0 , end = sum ; 
    while(st<=end){
        int mid = st + (end-st)/2 ;
        if(isvalid(mid,m,n,nums)){
            end = mid-1 ;
            ans = mid ;
        }else{
            st = mid +1 ;
        }
    }
    return ans ;
}

int main(){
vector<int>nums = {2,1,3,4};
int n = 4 , m = 2 ;
cout<<bookallocation(m,n,nums); 

}