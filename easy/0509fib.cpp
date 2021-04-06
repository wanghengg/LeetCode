#include <bits/stdc++.h>
using namespace std;

// 自顶向下，递归法
class Solution{
public:
    int helper(vector<int>& memo, int n) {
        if (n == 0 || n == 1) return n; // base case
        if (memo[n] != 0) return memo[n];   // 剪枝，已经计算过的不需要递归，直接从memo中查找，避免重复子问题
        memo[n] = helper(memo, n-1) + helper(memo, n-2);
        return memo[n];
    }
    int fib(int n) {
        vector<int> memo(n+1, 0);
        return helper(memo, n);
    }
};

// 自底向上，迭代法
class Solution1{
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

/*
 * 从迭代法中可以看到每次更新状态只依赖于前两个状态，所以不必要把所有状态保存下来
 */

class Solution2{
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        int pre = 0, cur = 1;
        for (int i = 2; i <= n; ++i) {
            int sum = pre + cur;
            pre = cur;
            cur = sum;
        }
        return cur;
    }
};

int main() {
    Solution2 solution;
    cout << solution.fib(3) << endl;
    return 0;
}