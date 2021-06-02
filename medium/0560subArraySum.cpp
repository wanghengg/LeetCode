//
// Created by wangheng on 2021/6/2.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int subArraySum(vector<int> &nums, int k) {
        int n = nums.size();
        // 构造前缀和，sum[i]就是nums[0...i-1]的和，sum[0] = 0
        vector<int> sum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i+1] = sum[i] + nums[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; j++) {
                if (sum[i] - sum[j] == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

class Solution1{
public:
    int subArraySum(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> preSum;
        preSum.insert({0,1});   // 前缀和为0的个数为1
        int ans = 0;
        int sum_i = 0;
        for (int i = 0; i < n; ++i) {
            sum_i += nums[i];
            int sum_j = sum_i - k;
            if (preSum.count(sum_j)) {
                ans += preSum[sum_j];
            }
            preSum[sum_i]++;
        }
        return ans;
    }
};

int main() {
    Solution1 solution;
    vector<int> nums{1,1,1};
    int k = 2;
    cout << solution.subArraySum(nums, k) << endl;

    return 0;
}