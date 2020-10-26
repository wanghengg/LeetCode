#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 暴力解法，直接将两个数组合并排序，然后取中间的数，时间复杂度O((m+n)log(m+n))，空间复杂度O(m+n)
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int totalLength = nums1.size() + nums2.size();
        if (totalLength == 0) return 0;
        nums.resize(totalLength);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
        sort(nums.begin(), nums.end());
        if (totalLength % 2 == 0) {
            return (nums[totalLength / 2 - 1] + nums[totalLength / 2]) / 2.0;
        } else {
            return nums[totalLength/2];
        }
    }
};

class Solution1{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) return 0;
        if (nums1.empty())
    }
};

int main() {
    vector<int> nums1{1,3}, nums2{2};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}