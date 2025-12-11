#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

void print(vector<int>nums){
    for(int i = 0 ; i < nums.size() ; i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

vector<int> prefixSum2D(vector<vector<int>> mat, vector<vector<int>> queries) {
        // code here
        int q = queries.size() ,n = mat.size() , m = mat[0].size();
        vector<int>ans(q) ;
        vector<vector<int>>nums(n , vector<int>(m)) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                nums[i][j] = mat[i][j];
                if(i-1>=0) nums[i][j] += nums[i-1][j];
                if(j-1>=0) nums[i][j] += nums[i][j-1];
                if(i-1>=0 && j-1 >=0) nums[i][j] -= nums[i-1][j-1];
            }
        }
        for(int i= 0 ; i < q ; i++){
            int r1 = queries[i][0] , c1 = queries[i][1] , r2 = queries[i][2] , c2 = queries[i][3];
            
            ans[i] = nums[r2][c2] ;
            
            //delete upper matrix
            if(r1-1>=0) ans[i]-=nums[r1-1][c2];
            
            //delete the left matrix
            if(c1-1>=0) ans[i] -= nums[r2][c1-1];
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout<<nums[i][j]<<' ';
            }
            cout<<endl ;
        }
        return ans ;
    }


int main(){
    vector<int>nums  = prefixSum2D({{1,1,1},{1,1,1},{1,1,1}} , {{1,1,2,2} });
    print(nums);
    return 0 ;
}