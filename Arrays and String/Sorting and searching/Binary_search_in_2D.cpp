#include <iostream>
#include <vector>
using namespace std;

/*
The idea is to consider the given matrix as 1D array and apply only one binary search.
For example, for a matrix of size n x m and we can consider it as a 1D array of size n*m, 
then the first index would be 0 and last index would n*m-1. 
So, we need to do binary search from low = 0 to high = (n*m-1).


Since each row of mat[][] will have m elements, so we can find the row of the element as (mid / m) and 
the column of the element as (mid % m). Then, we can compare x with arr[mid/m][mid%m] for each mid and
complete our binary search.

*/

bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size(), m = mat[0].size();

    int lo = 0, hi = n * m - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
      
        // find row and column of element at mid index
        int row = mid / m;
        int col = mid % m;
      
        // if x is found, return true
        if (mat[row][col] == x) 
            return true;
      
        // if x is greater than mat[row][col], search 
        // in right half
        if (mat[row][col] < x) 
            lo = mid + 1;
        
        // if x is less than mat[row][col], search 
        // in left half
        else 
            hi = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{1, 5, 9}, 
                               {14, 20, 21}, 
                               {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}