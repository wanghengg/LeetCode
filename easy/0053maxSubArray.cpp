#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
     * f(i)表示以第i个数字结尾的连续子数组的最大和，我们要的答案是max(f(i)), 0 <= i <= n-1;
     * 因为需要求出每个f(i)，然后返回f(i)最大值即可
     * f(i) = max(f(i-1) + nums[i], nums[i]);
     * 如果f(i)加上nums[i]之后小于nums[i]，应该抛弃之前的子数组，从新开始计算子数组和
     */
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxNum = nums[0];
        for (auto& iter : nums) {
            pre = max(pre + iter, iter);
            maxNum = max(pre, maxNum);
        }
        return maxNum;
    }
};