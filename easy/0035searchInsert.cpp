#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                return mid;
            } else {
                right = mid - 1;
            }
        }
        if (nums[left] < target) {
            return left + 1;
        } else {
            return left;
        }
    }
};

int main() {
    vector<int> nums{1,3,5,6};
    int target = 7;
    Solution solution;
    cout << solution.searchInsert(nums, target) << endl;
    return 0;
}