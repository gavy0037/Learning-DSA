#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size();        
    int m = mat[0].size();    

    int low = 0, high = n * m - 1;  
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // convert 1D index to 2D coordinates
        int row = mid / m;
        int col = mid % m;
        int midVal = mat[row][col];

        // check if mid element is the target
        if (midVal == x) {
            return true;
        }

        // get value at virtual low position
        int lowRow = low / m;
        int lowCol = low % m;
        int lowVal = mat[lowRow][lowCol];

        // if left half is sorted
        if (lowVal <= midVal) {
            
            // check if x lies within the left 
            // sorted half
            if (lowVal <= x && x < midVal) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // right half is sorted
            int highRow = high / m;
            int highCol = high % m;
            int highVal = mat[highRow][highCol];

            // check if x lies within the right
            // sorted half
            if (midVal < x && x <= highVal) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    // x not found in the matrix
    return false;
}

int main() {
    vector<vector<int>> mat = {
        {7, 8, 9, 10},
        {11, 12, 13, 1},
        {2, 3, 4, 5}
    };
    int x = 3;

    if (searchMatrix(mat, x)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}