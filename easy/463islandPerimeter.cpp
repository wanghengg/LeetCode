#include <iostream>
#include <vector>
using namespace std;

class Solution{
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j]) {
                    int cnt = 0;
                    for (int k = 0; k < 4; ++k) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        // 当前边能被视为岛屿周长的条件是当且仅当这条边为网格的边界或者相邻的另一个格子为水域
                        if (tx < 0 || tx >= rows || ty < 0 || ty >= columns || !grid[tx][ty]) {
                            cnt += 1;
                        }
                    }
                    ans += cnt;
                }
            }
        }
        return ans;
    }
};

constexpr  int Solution::dx[4];
constexpr  int Solution::dy[4];

int main() {
    Solution solution;
    vector<vector<int>> grid{{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
    cout << solution.islandPerimeter(grid) << endl;

    return 0;
}