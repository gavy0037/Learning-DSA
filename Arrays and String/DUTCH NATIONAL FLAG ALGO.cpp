#include<iostream>
#include<vector>
using namespace std ;
void sortColors(vector<int>& nums) {
        int mid = 0 , high = nums.size()-1 ,low = 0 ;
        while(mid<=high){
            if(nums[mid] == 0 ){
                swap(nums[mid],nums[low]);
                low++;
                mid++; 
            }else if (nums[mid] == 2 ){
                swap(nums[mid],nums[high]);
                high--;
            }else{
                mid++;
            }
        }
    }


int main(){
vector<int>vec = {1,2,1,2,1,0,1,1,0,0,0,2,0,1,0,1,2,0,1,2,0};
sortColors(vec);
for(int i = 0 ; i < vec.size() ; i++){
    cout<<vec[i]<<" ";
}
    return 0 ;
}