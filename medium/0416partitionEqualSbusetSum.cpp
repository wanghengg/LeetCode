#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution{
public:
    // 问题转换为能否从数组中选出部分数使得这些数之和等于数组所有元素之和的一半，将题目转化为
    // 0-1背包问题，target是数组元素之和的一半
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;  // 数组长度小于2不能划分，返回false
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;     // 如果求和为奇数，不能平分所以直接返回false
        int target = sum / 2;
        int maxNum = *max_element(nums.begin(), nums.end());
        if (maxNum > target) return false;
        int length = nums.size();
        // dp[i][j]表示从数组[0,i]下标范围内选取若干个正整数，是否存在一种选取方案使得被选取
        // 的正整数之和等于j，初始化时dp所有元素均为false
        // 最终要求的结果应该是dp[nums.size() - 1][target]
        vector<vector<int>> dp(length, vector<int>(target+1, 0));
        for (int i = 0; i < length; i++) {
            dp[i][0] = true;    // 目标为0，所以对于任何范围取0个元素即可满足条件
        }
        dp[0][nums[0]] = true;  // 当选择范围为只包含第一个元素时，如果选择，target为nums[0]，所以dp[0][nums[0]]为true
        for (int i = 1; i < length; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    // 如果target大于nums[i]，那么说明可以继续添加数，有两种情况，一种是选择nums[i]，一种是不选择nums[i]
                    dp[i][j] = dp[i-1][j-num] | dp[i-1][j];
                } else {
                    // 如果target小于nums[i]，说明不能选择nums[i]，则dp[i][j] = dp[i-1][j]
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[length-1][target];
    }
};

class Solution1{
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;    // 数组长度小于2，不可划分，直接返回false
        int sum = accumulate(nums.begin(), nums.end(), 0);  // 计算数组nums的和
        if (sum & 1) return false;  // 如果sum是奇数，不能分为两部分，直接返回false
        int target = sum / 2;
        int maxNum = *max_element(nums.begin(), nums.end());
        if (maxNum > target) return false;  // 如果最大值直接大于target，那么数组不可分为和相等的两部分，直接返回false
        vector<int> dp(target+1, 0);   // 只用一维数组解决0-1背包问题
        dp[0] = true;   // 和为0可以组成
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int j = target; j >= num; --j) {
                dp[j] |= dp[j-num];
            }
        }
        return dp[target];
    }
};

int main() {
    vector<int> nums = {1,5,5,11};
    Solution solution;
    cout << boolalpha << solution.canPartition(nums) << endl;

    return 0;
}