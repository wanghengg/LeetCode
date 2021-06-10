//
// Created by wangheng on 2021/6/10.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
     * 此题和背包问题很相似，不同点在于经典背包问题只有一个背包容量约束条件，但是这道题有最小利润和员工总人数两个约束条件，
     * 所以动态规划的表应该是3维。三个维度分别是：当前可以选择的工作，已选择的小组员工人数，以及目前状态的工作获利下限
     * dp[i][j][k]表示在前i个工作中选择了j个员工(刚好j个员工)并且满足工作利润至少为k的情况下的盈利计划的总数目
     */
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int len = group.size();
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(n+1, vector<int>(minProfit+1)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= len; ++i) {
            int members = group[i-1];   // 第i个工作所需的人数
            int earn = profit[i-1]; // 第i个工作的利润
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    if (j < members) {  // 员工数比第i个工作所需要的员工数小
                        dp[i][j][k] = dp[i-1][j][k];
                    } else {
                        /*
                         * max(0, k-earn)的意义：
                         * 当第i个工作的利润已经超过minProfit时，说明前面的任务都不需要选择，而且dp数组第三维是工作利润至少为k，
                         * 将k-earn<0的情况包含在k=0的情况中
                         */
                        dp[i][j][k] =  (dp[i-1][j][k] + dp[i-1][j-members][max(0, k-earn)]) % 1000000007;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= n; ++i) {
            sum += dp[len][i][minProfit];
            sum %= 1000000007;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    int n = 5;
    int minProfit = 3;
    vector<int> group{2,2};
    vector<int> profit{2,3};
    cout << solution.profitableSchemes(n, minProfit, group, profit) << endl;

    return 0;
}