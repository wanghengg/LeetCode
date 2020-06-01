//
// Created by wangheng on 2020/6/1.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> result(m, vector<int>(n,0));
        int i, j;
        for (i = 0; i < m; ++i)  {
            if (obstacleGrid[i][0] != 1)
                result[i][0] = 1;
            else
                break;
        }
        for (; i < m; ++i)
            result[i][0] = 0;
        for (j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] != 1)
                result[0][j] = 1;
            else
                break;
        }
        for (; j < n; ++j)
            result[0][j] = 0;
        for (i = 1; i < m; ++i) {
            for (j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] != 1)
                    result[i][j] = result[i - 1][j] + result[i][j - 1];
                else
                    result[i][j] = 0;
            }
        }
        return result[i-1][j-1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> obstacleGrid{{1,0}};
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}