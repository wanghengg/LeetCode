//
// Created by wangheng on 2021/4/14.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1,-1};
        vector<int> result;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left < nums.size() && nums[left] == target) {
            result.emplace_back(left);
        } else {
            result.emplace_back(-1);
            result.emplace_back(-1);
            return result;
        }
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        result.emplace_back(right);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums{5,7,7,8,8,10};
    int target = 11;
    vector<int> result = solution.searchRange(nums, target);
    for(auto& iter : result) {
        cout << iter << endl;
    }

    return 0;
}