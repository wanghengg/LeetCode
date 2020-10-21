#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        if (matrix.size() == 1) return matrix[0];
        vector<int> res;
        int left = 0, right = matrix[0].size() - 1;
        int up = 0, down = matrix.size() - 1;
        while (left <= right && up <= down) {
            int i = left;
            for (; i <= right; i++) {
                res.push_back(matrix[up][i]);
            }
            up++;
            i = up;
            for (; i <= down; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            i = right;
            if (up > down || left > right) break;
            for (; i >= left; i--) {
                res.push_back(matrix[down][i]);
            }
            down--;
            i = down;
            if (up > down || left > right) break;
            for (; i >= up; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix{{2,5,8}, {4,0,-1}};
    vector<int> res = solution.spiralOrder(matrix);
    for(auto &iter : res) {
        cout << iter << ' ';
    }
    return 0;
}