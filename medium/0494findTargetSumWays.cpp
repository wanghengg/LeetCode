//
// Created by wangheng on 2021/6/7.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int result = 0;
    void backtracking(vector<int>& nums, int i, int curSum, int target) {
        // i表示加上nums[i]，curSum表示当前和
        if (i == nums.size() - 1 && (curSum + nums[i] == target || curSum - nums[i] == target)) {   // i为最后一个元素且当前和等于target
            if (nums[i] == 0) { // 如果nums[i]恰好为0，+0或者-0都可以，所以总次数+2
                result += 2;
            } else {    // 其他情况总次数+1
                result += 1;
            }
            return;
        }
        if (i == nums.size() - 1) return;   // 不满足总和等于target但是已经遍历完数组，所以返回，否则会死循环
        backtracking(nums, i+1, curSum+nums[i], target);
        backtracking(nums, i+1, curSum-nums[i], target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        backtracking(nums, 0, 0, target);
        return result;
    }
};

/*
 * 根据添加“+”号还是“-”号将数组划分为“正值部分和”与“负值部分和”，令负值部分和为m，假设数组元素总和为s，那么
 * 正值部分和为(s-m)，满足(s-m)-m = target, 则m = (s-target)/2;
 * 所以问题转化为从数组nums中选择任意个数，使得选择出来的元素之和为m，是一个0-1背包问题
 * 定义dp[i][j]为在nums中从前i个元素中选择任意个其和为j的方案数,dp[0][0] = 1表示不选择元素并且和为0的方案有1个
 * 如果nums的第i个元素nums[i-1]大于j，表示不可以选择nums[i-1]，那么dp[i][j] = dp[i-1][j]，
 * 否则可以选择nums[i-1](dp[i-1][j-nums[i-1]])或者不选择nums[i-1](dp[i-1][j])，有两种情况，则dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
 */

class Solution1{
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - target;
        if (diff < 0 || diff % 2 == 1) return 0;
        int m = diff / 2;
        int len = nums.size();
        vector<vector<int>> dp(len+1, vector<int>(m+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                int num = nums[i-1];
                if (num <= j) {
                    dp[i][j] += dp[i-1][j-num];
                }
            }
        }
        return dp[len][m];
    }
};

int main() {
    Solution1 solution;
    vector<int> nums{1,1,1,1,1};
    int target = 3;
    cout << solution.findTargetSumWays(nums, target) << endl;
    return 0;
}