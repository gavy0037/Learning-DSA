#include<iostream>
#include<vector>
#include<stack>

using namespace std ;

int maximalRectangle(vector<vector<char>>& matrix) { // my_solution
    int m = matrix.size() , n = matrix[0].size();
    vector<vector<int>>heights(m , vector<int>(n , 0));
    for(int i = 0 ; i < n ; i++){
        heights[0][i] = matrix[0][i]-'0';
    }
    for(int i = 1 ; i < m ; i++){
        for(int j = 0 ; j < n; j++){
            if(matrix[i][j] == '0') heights[i][j] = 0 ;
            else{
                heights[i][j] = 1+heights[i-1][j];
            }
        }
    }

    vector<vector<int>> left_smaller( m , vector<int>(n ,0)) , right_smaller( m , vector<int>(n ,0));

    for(int i = 0 ; i < m ; i++){
        stack<int>stk ;
        for(int j = 0 ; j < n ; j++){
            while(!stk.empty() && heights[i][stk.top()] >= heights[i][j]) stk.pop();

            if(stk.empty()){
                left_smaller[i][j] = -1;
            }else left_smaller[i][j] = stk.top();

            stk.push(j);
        }
    }
    for(int i = 0 ; i < m ; i++){
        stack<int>stk;
        for(int j = n-1 ; j >= 0 ; j--){
            while(!stk.empty() && heights[i][stk.top()] >= heights[i][j]) stk.pop();

            if(stk.empty()) right_smaller[i][j] = n ;
            else right_smaller[i][j] = stk.top();

            stk.push(j);
        }
    }

    int max_area = 0 ;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ;j++){
            int h = heights[i][j] ;
            int left = left_smaller[i][j] , right = right_smaller[i][j] ;

            max_area = max(max_area , h*(right-left-1));
        }
    }

    
    return max_area ;
}




/*                       More optimized Code                      */
class Solution {
public:
    // Helper function to solve the "Largest Rectangle in Histogram" problem
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int max_a = 0;
        
        for (int i = 0; i <= n; i++) {
            // Use a dummy height of 0 at the end (i == n) to flush the stack
            int current_height = (i == n) ? 0 : heights[i];
            
            while (!stk.empty() && heights[stk.top()] >= current_height) {
                int h = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                max_a = max(max_a, h * width);
            }
            stk.push(i);
        }
        return max_a;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int max_area = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Update heights for the current row
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            // For each row, calculate the max area in the current histogram
            max_area = max(max_area, largestRectangleArea(heights));
        }

        return max_area;
    }
};