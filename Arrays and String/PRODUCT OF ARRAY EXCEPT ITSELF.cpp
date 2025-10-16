#include<iostream>
#include<vector>
using namespace std ;

vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
        vector<int>product(n,1);
        int prefix = 1 ,sufix = 1;

        for(int i = 0 ; i < n; i ++){
           product[i] *=prefix ;
           prefix*=nums[i];
 }

 for(int i = nums.size() - 1 ; i >=0 ; i--){
    product[i]*=sufix;
    sufix*=nums[i];
 }


        return product ;


} 


int main (){
    vector<int>nums = {1,2,3,4};
    vector<int>vec =  productExceptSelf(nums);
    for(int i = 0 ; i < nums.size() ; i ++){
        cout<<vec[i]<<" ";
    }
return 0 ;
}



//     vector<int>vec;
//     for(int i = 0 ; i < nums.size() ; i ++ ){
//         int st = 0 , end = nums.size() - 1 ;
//         int product = 1 ;
//         while(i>st){
//             product *= nums[st];
//             st++;
//         }
//         while(i < end){
//             product *= nums[end];
//             end-- ;
//         }
//         vec.push_back(product);
//     }
//     return vec ;







//    vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>prefix(n,1);
//         vector<int>sufix(n,1);
//         vector<int>product(n,1);
//         //prefix
//     for(int i = 1 ; i < nums.size(); i ++){
//         prefix[i] = prefix[i -1]*nums[i-1];

//     }
    
//     for(int i = n-2 ; i >=0 ; i--){
//         sufix[i] = sufix[i+1]*nums[i+1];
//     }

// for(int i = 0 ; i <nums.size() ; i ++){
//     product[i] = prefix[i]*sufix[i];
// }
// return product ;

//     }