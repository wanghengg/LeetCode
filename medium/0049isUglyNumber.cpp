#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // 用一个set保存已经发现的丑数
    set<int> uglys;
    // 如果一个数是丑数，那么它乘以2、3、5也会是丑数
    int nthUglyNumber(int n) {
        if (n == 0) return 0;
        int count = 1;
        uglys.insert(1);
        auto it = uglys.cbegin();
        while (count != n) {
            uglys.insert((*it) * 2);
            uglys.insert((*it) * 3);
            uglys.insert((*it) * 5);
            ++count;
            ++it;
        }
        return *it;
    }
};

class Solution1{
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int n2 = dp[a] * 2;
            int n3 = dp[b] * 3;
            int n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);
            if (dp[i] == n2) ++a;
            if (dp[i] == n3) ++b;
            if (dp[i] == n5) ++c;
        }
        return dp[n-1];
    }
};