//
// Created by wangheng on 2020/5/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 动态规划+滚动数组，时间复杂度O(n)，空间复杂度O(1)
 *
 * 首先考虑最简单的情况。如果只有一间房屋，则偷窃该房屋，可以偷窃到最高总金额。如果只有两间房屋，
 * 则由于两间房屋相邻，不能同时偷窃，只能偷窃其中的一间房屋，因此选择其中金额较高的房屋进行偷窃，
 * 可以偷窃到最高总金额。
 * 如果房屋数量大于两间，应该如何计算能够偷窃到的最高总金额呢？对于第 k~(k>2)k (k>2) 间房屋，
 * 有两个选项：
 *
 */
class Solution{
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> states(n, 0);
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int temp = second;
            second = max(second, first + nums[i]);
            first = temp;
        }
        return second;
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,3,2,9};
    cout << solution.rob(nums) << endl;

    return 0;
}