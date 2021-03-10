#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    // 暴力解法，时间复杂度O(n^2)
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        int max = INT_MIN;
        for (int i = 0; i < length; ++i) {
            int sum = 0;
            for (int j = i; j < length; ++j) {
                sum += nums[j];
                max = (sum > max) ? sum : max;
            }
        }
        return max;
    }

    // 动态规划，dp[i]表示以nums[i]结尾的子数组的和的最大值
    // 如果dp[i-1]>0，则dp[i] = dp[i-1] + nums[i]；
    // 否则，dp[i] = nums[i]
    int maxSubArray1(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length, 0);
        dp[0] = nums[0];
        for (int i = 1; i < length; ++i) {
            if (dp[i-1] > 0) {
                dp[i] = dp[i-1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout << solution.maxSubArray1(nums) << endl;

    return 0;
}