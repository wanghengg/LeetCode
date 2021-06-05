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

// 简化上面的答案
class Solution1{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));   // 将全部位置初始为0
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1)    // 如果第一列当前位置有障碍物，则其下面的位置都不可到达
                break;
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1)
                break;
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] != 1) {  // 如果当前位置有障碍物，则dp[i][j]不变仍为0
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> obstacleGrid{{1,0}};
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}