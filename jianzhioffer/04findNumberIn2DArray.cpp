#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    // 暴力解法
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (auto & i : matrix) {
            if (find(i.begin(), i.end(), target) != i.end()) {
                return true;
            }
        }
        return false;
    }

    // 从矩阵的右上角看可以看做一个二叉搜索树
    bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22},{10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    Solution solution;
    int target = 5;
    cout << boolalpha << solution.findNumberIn2DArray1(matrix, target) << endl;
    return 0;
}