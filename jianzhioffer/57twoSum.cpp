//
// Created by wangheng on 2021/4/10.
//

#include <bits/stdc++.h>
using namespace std;

// 模仿两数之和，但是没有用到已排序数组的性质
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> data;
        for (auto& iter : nums) {
            auto res = data.find(target - iter);
            if (res != data.end()) {
                return {iter, *res};
            } else {
                data.insert(iter);
            }
        }
        return {};
    }
};

// 因为数组本身有序，可以使用双指针，当左右指针指向的两数之和大于target时，right指针减1，当左右
// 指针指向的两数之和小于target时，left指针加1
class Solution1{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return {nums[left], nums[right]};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums{2,7,11,15};
    int target = 9;
    Solution1 solution;
    vector<int> result = solution.twoSum(nums, target);
    for (auto& iter : result) {
        cout << iter << ' ';
    }
    return 0;
}