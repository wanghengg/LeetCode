#include <bits/stdc++.h>
using namespace std;

// 改变了数组本身的值
class Solution{
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (target >= nums[0]) {
                // 目标值在左半段时，若mid在右半段，则将mid索引的值改为inf
                if (nums[mid] < nums[0]) {
                    nums[mid] = INT_MAX;
                }
            } else {
                // 目标值在右半段，若mid在左半段，则将mid索引的值改为-inf
                if (nums[mid] >= nums[0]) {
                    nums[mid] = INT_MIN;
                }
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

// 不改变数组本身的值
class Solution1{
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) { // 坐半部分有序
                if (target >= nums[0] && target < nums[mid]) {  // 看做有序数组的查找
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {    // 右半部分有序
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};