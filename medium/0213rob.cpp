//
// Created by wangheng on 2021/4/15.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // 由于所有的房屋围成一圈，所以首尾相连，不能同时偷第一个和最后一个房屋
    // 因此如果偷第一个房屋，那么不偷最后一个房屋，偷窃范围为[0,n-2]
    // 如果偷最后一个房屋，那么不偷第一个房屋，偷窃范围为[1,n-1]
    // 然后和198题一样的解法
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int length = nums.size();
        vector<int> dp(length - 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < length -1; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int result = dp[length-2];
        dp.clear();
        dp.resize(length - 1, 0);
        dp[0] = nums[1];
        dp[1] = max(nums[1], nums[2]);
        for (int i = 2; i < length - 1; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i+1]);
        }
        result = max(result, dp[length - 2]);
        return result;
    }
};

int main() {
    vector<int> nums{1,2,3};
    Solution solution;
    cout << solution.rob(nums) << endl;
    return 0;
}