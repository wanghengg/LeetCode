//
// Created by wangheng on 2021/6/10.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// 不用数组
class Solution1{
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        int res;
        for (int i = 2; i <= n; ++i) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};

int main() {
    Solution1 solution;
    int n = 10;
    cout << solution.climbStairs(n) << endl;
    return 0;
}