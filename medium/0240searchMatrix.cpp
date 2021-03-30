#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int up = 0, right = columns - 1;
        while (up < rows && right >= 0) {
            if (matrix[up][right] == target) {
                return true;
            } else if (matrix[up][right] > target) {
                right--;
            } else {
                ++up;
            }
        }
        return false;
    }
};