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