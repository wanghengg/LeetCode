//
// Created by wangheng on 2020/6/1.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m+1, vector<int>(n+1));
        for (int i = 0, j = 0; i <= m; ++i)
            result[i][j] = 0;
        for (int i = 0, j = 1; j <= n; ++j)
            result[i][j] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j)
                result[i][j] = max(result[i][j-1], result[i-1][j]) + grid[i-1][j-1];
        }
        return result[m][n];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid{{1,3,1}, {1,5,1}, {4,2,1}};
    cout << solution.maxValue(grid) << endl;

    return 0;
}