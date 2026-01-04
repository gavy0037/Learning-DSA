// You are given an array that was originally sorted in increasing order, but exactly two elements were swapped.
// Your task is to identify those two elements (or swap them back) to restore the sorted order.

#include<iostream>
#include<vector>

using namespace std ;


void recoverSortedArray(vector<int>& arr) {
    int n = arr.size();
    int first = -1, second = -1;

    // Step 1: find violations
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            if (first == -1) {
                first = i;
            }
            second = i + 1;
        }
    }

    // Step 2: swap the misplaced elements
    swap(arr[first], arr[second]);
}