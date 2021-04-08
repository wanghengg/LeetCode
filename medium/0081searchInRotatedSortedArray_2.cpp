//
// Created by wangheng on 2021/4/8.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 1) return nums[0] == target;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[left] == nums[mid]) {
                ++left;
                continue;
            }
            if (nums[left] < nums[mid]) {   // 左边有序
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {    // 右边有序
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

class Solution1{
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[left] < nums[mid]) {   // 左边有序
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[left] > nums[mid]) {   // 右边有序
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {    // 无法确定哪部分有序
                ++left;
            }
        }
        return false;
    }
};