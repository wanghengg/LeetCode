#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int left = 0, right = columns * rows - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid/columns][mid%columns] == target) {
                return true;
            } else if (matrix[mid/columns][mid%columns] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};