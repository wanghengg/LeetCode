//
// Created by wangheng on 2020/6/8.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return {};
        // 将nums排序，对排序数组查找两个数之和等于-nums[i]，时间复杂度为O(n)
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < len - 2; ++i) {
            // 如果第一个数大于0，-nums[i]小于0，由于是有序数组，后面的数全都大于零，
            // 所以不存在两数之和等于负数
            if (nums[i] > 0) break;
            if (i == 0 || nums[i] != nums[i-1]) {
                int j = i + 1, k = len - 1; // 双指针
                while (j < k) {
                    // 当两数之和小于结果时，由于数组时有序的，所以++j，第一个指针右移
                    if (nums[j] + nums[k] < -nums[i]) {
                        ++j;
                        while (j < k && nums[j] == nums[j-1]) ++j;
                    }
                    else if (nums[j] + nums[k] == -nums[i]) {
                        result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                        --k;
                        ++j;
                        // 得到一个结果之后，右移第一个指针直到指向不同的数字，
                        // 左移第二个指针直到指向不同的数字，避免重复的结果
                        while (j < k && nums[j] == nums[j-1]) ++j;
                        while (j < k && nums[k] == nums[k+1]) --k;
                    } else {
                        --k;
                        while (j < k && nums[k] == nums[k+1]) --k;
                    }
                }
            }
        }
        return result;
    }
};

class Solution1{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int first = 0; first < n-2; first++) {
            if (first > 0 && nums[first] == nums[first-1]) continue;    // 重复元素直接往后
            int third = n-1;
            int target = -nums[first];
            for(int second = first+1; second < n-1; ++second) {
                if (second > first+1 && nums[second] == nums[second-1]) {
                    continue;
                }
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                if (second == third) break;
                if (nums[second] + nums[third] == target) {
                    res.emplace_back(vector<int>{nums[first], nums[second], nums[third]});
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4, 0, 1};
    Solution solution;
    auto result = solution.threeSum(nums);
    for (auto& vec : result) {
        for (auto &i : vec)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}