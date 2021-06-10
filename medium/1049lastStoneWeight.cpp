//
// Created by wangheng on 2021/6/8.
//

#include <bits/stdc++.h>
using namespace std;

// 这道题主要涉及到数学思路
class Solution{
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        int neg = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(neg+1));  // dp[i][j]表示前i个元素能否组成和为j
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= neg; ++j) {
                if (j < stones[i]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i]];
                }
            }
        }

        for (int m = neg; ; --m) {
            if (dp[n][m]) {
                return sum - 2 * m;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> stones{2,7,4,1,8,1};
    cout << solution.lastStoneWeightII(stones) << endl;
    return 0;
}