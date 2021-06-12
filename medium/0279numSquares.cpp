//
// Created by wh969 on 2021/6/11.
//

#include <bits/stdc++.h>
using namespace std;

/*
 * 此题明显是一个完全背包问题，“物品”的数量没有限制
 * dp[i]表示和为i的完全平方数的最小个数，显然,dp[0] = 0
 */
class Solution{
public:
    int numSquares(int n) {
        // 和为n的完全平方数里面最大的是sqrt(n) * sqrt(n)
        // 可能构成和为n的完全平方数
        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.emplace_back(i*i);
        }
        vector<int> dp(n+1, n+1);   // n最多由n个1^2构成，不可能是n+1
        dp[0] = 0;  // 初始条件，和为0，完全平方数为0
        for (int i = 1; i <= n; ++i) {
            for (auto& iter : squares) {
                if (i < iter) break;
                dp[i] = min(dp[i-iter]+1, dp[i]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 13;
    cout << solution.numSquares(n) << endl;

    return 0;
}