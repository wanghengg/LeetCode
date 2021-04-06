#include <bits/stdc++.h>
using namespace std;

// 暴力解法
class Solution{
public:
    int coinChange(vector<int>& coins, int amount) {
        // base case
        if (amount == 0) return 0;
        if (amount < 0) return -1;  // amount为负数，说明不能这样凑，根据题目意思返回-1
        int res = INT_MAX;
        for (auto& coin : coins) {
            int subProblem = coinChange(coins, amount - coin);  // 子问题的解
            if (subProblem == -1) continue; // 不能凑够，继续
            res = min(res, 1 + subProblem);     // 当前最好的解法
        }
        return (res == INT_MAX) ? -1 : res;     // 不存在解返回-1
    }
};

// 自顶向下，递归解法
class Solution1{
public:
    int dp(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != INT_MIN) {
            return memo[amount];    // 避免重复子问题重复求解，剪枝
        }

        int res = INT_MAX;
        for (auto& coin : coins) {
            int subProblem = dp(coins, amount - coin, memo);
            if (subProblem == -1) continue;
            res = min(res, 1 + subProblem);
        }
        memo[amount] = (res == INT_MAX) ? -1 : res;
        return memo[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, INT_MIN);    // 备忘录，记录每次已经得到的组合方式，剪枝，避免重复子问题
        return dp(coins, amount, memo);
    }
};

// 自底向上，迭代解法
class Solution2{
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);  // dp[i]表示凑够总金额为i所需最少硬币数量
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto& coin : coins) {
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

int main() {
    Solution2 solution;
    vector<int> coins{2,5};
    int amount = 11;
    cout << solution.coinChange(coins, amount) << endl;
    return 0;
}