#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) return false;
        // dp[i][j]表示s3的前i+j个字符由s1的前i个和s2的前j个字符组成交错字符串
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i >= 1) {
                    dp[i][j] = dp[i][j] || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
                if (j >= 1) {
                    dp[i][j] = dp[i][j] || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return dp[m][n];
    }
};