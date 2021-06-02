//
// Created by wangheng on 2021/6/2.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    // 当preSum[i]-preSum[i]为K的倍数时，preSum[i]和preSum[j]除以K的余数相同，
    // 因此只需要计算每个下标对应的前缀和除以K的余数即可，使用哈希表存储每个余数第一次出现的下标
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        unordered_map<int, int> preSum;
        preSum.insert({0, -1});
        int ans = 0;
        int remainder = 0;  // 存储余数
        for (int i = 0; i < n; ++i) {
            remainder = (remainder + nums[i]) % k;  // nums[0...i-1]前缀和除K的余数
            if (preSum.count(remainder)) {
                int preIndex = preSum[remainder];
                if (i - preIndex >= 2) {
                    return true;
                }
            } else {
                preSum[remainder] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{23, 2, 4, 6, 7};
    int k = 6;
    cout << solution.checkSubarraySum(nums, k) << endl;

    return 0;
}