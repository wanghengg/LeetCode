#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution{
public:
    bool lessThanK(const pair<int, int>& p, int k) {
        int first = p.first;
        int second = p.second;
        int sum = 0;
        while (first) {
            sum += first % 10;
            first /= 10;
        }
        while (second) {
            sum += second % 10;
            second /= 10;
        }
        return sum <= k;
    }

    bool isValid(const pair<int, int>& p, int m, int n) {
        if (p.first >= 0 && p.first < m && p.second >= 0 && p.second < n)
            return true;
        return false;
    }

    // 深度优先搜索，用栈实现
    int movingCount(int m, int n, int k) {
        if (m <= 0 || n <= 0) return 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        stack<pair<int, int>> point;
        point.push({0,0});
        int count = 0;
        visited[0][0] = 1;
        while (!point.empty()) {
            auto p = point.top();
            point.pop();
            if (lessThanK(p, k))
                ++count;
            pair<int, int> left{p.first, p.second-1};
            if (lessThanK(left, k) && isValid(left, m, n) && !visited[left.first][left.second]) {
                point.push(left);
                visited[left.first][left.second] = 1;
            }
            pair<int, int> right{p.first, p.second+1};
            if (lessThanK(right, k) && isValid(right, m, n) && !visited[right.first][right.second]) {
                point.push(right);
                visited[right.first][right.second] = 1;
            }
            pair<int, int> up{p.first-1, p.second};
            if (lessThanK(up, k) && isValid(up, m, n) && !visited[up.first][up.second]) {
                point.push(up);
                visited[up.first][up.second] = 1;
            }
            pair<int, int> down{p.first+1, p.second};
            if (lessThanK(down, k) && isValid(down, m, n) && !visited[down.first][down.second]) {
                point.push(down);
                visited[down.first][down.second] = 1;
            }
        }
        return count;
    }

    // 广度优先搜索，用队列实现
    int movingCount1(int m, int n, int k) {
        if (!k) return 1;
        queue<pair<int, int>> points;
        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        points.push({0, 0});
        visited[0][0] = 1;
        int ans = 1;
        while (!points.empty()) {
            auto p = points.front();
            points.pop();
            for (int i = 0; i < 2; ++i) {
                int tx = p.first + dx[i];
                int ty = p.second + dy[i];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || visited[tx][ty] || !lessThanK({tx, ty}, k))
                    continue;
                points.push({tx, ty});
                visited[ty][ty] = 1;
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    int m = 16, n = 8, k = 4;
    Solution solution;
    cout << solution.movingCount1(m, n, k) << endl;
    return 0;
}