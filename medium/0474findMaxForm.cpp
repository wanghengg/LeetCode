#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // 可以看做背包问题，定义dp[i][j][k]为前i个元素中最多有j个0和k个1的最大子集的大小
    // 记第i个元素中0的个数为zeros，1的个数为ones，如果zeros > j或者ones > k，子集不能包含strs[i]，那么dp[i][j][k] = dp[i-1][j][k]
    // 如果zeros<=j并且ones<=k，如果考虑选择第i个元素，dp[i][j][k] = dp[i-1][j-zeros][k-ones]+1，如果不考虑选择第i个元素，那么
    // dp[i][j][k] = dp[i-1][j][k]，所以dp[i][j][k] = max(dp[i-1][j-zeros][k-ones]+1, dp[i-1][j][k])

    /*
     * 基准：如果i为0，即不选择任何元素，那么无论j和k为任何值，最大子集就是空集，大小为0，dp[0][j][k] = 0
     */
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    vector<int> zerosOnes = getZerosOnes(strs[i-1]);
                    int zeros = zerosOnes[0];
                    int ones = zerosOnes[1];
                    if (zeros <= j && ones <= k) {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zeros][k-ones]+1);
                    } else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[len][m][n];
    }

    // 判断字符串中0和1的个数
    vector<int> getZerosOnes(string& str) {
        vector<int> res(2, 0);
        for(auto& iter : str) {
            if (iter == '0') {
                res[0]++;
            } else {
                res[1]++;
            }
        }
        return res;
    }
};

class Solution1{
public:
    // 判断字符串中0和1的个数
    vector<int> getZerosOnes(string& str) {
        vector<int> res(2, 0);
        for(auto& iter : str) {
            if (iter == '0') {
                res[0]++;
            } else {
                res[1]++;
            }
        }
        return res;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int len = strs.size();
        for (int i = 0; i < len; ++i) {
            vector<int> zerosOnes = getZerosOnes(strs[i]);
            int zeros = zerosOnes[0];
            int ones = zerosOnes[1];
            for(int j = m; j >= zeros; --j) {
                for (int k = n; k >= ones; --k) {   // j和k倒序避免覆盖掉i-1次循环中的dp[j][k]和dp[j-zeros][k-ones]
                    dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones]+1);    // 循环中已经保证了j>=zeros && k>=ones，所以直接找dp[j][k]和dp[j-zeros][k-ones]+1中的最大值
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution1 solution;
    vector<string> strs{"1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101","1101","0101"};
    int m = 100;
    int n = 100;
    cout << solution.findMaxForm(strs, m, n) << endl;
    return 0;
}