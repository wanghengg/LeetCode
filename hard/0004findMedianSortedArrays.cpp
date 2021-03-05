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

/*
 * 因为两个数组的长度已知，所以中位数的下标也是已知的，用两个指针分别指向两个数组下标0的位置，每次将指向较小值的指针
 * 后移一位(如果一个指针已经到达数组末尾，则只需要移动另一个数组的指针)，知道达到中位数的位置，这种实现的时间复杂度
 * 是O(m+n)，空间复杂度是O(1)
 */
class Solution1{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        int length = nums1.size() + nums2.size();
        int mid;    // 中位数的位置，或者两个中位数的第一个位置
        if (length % 2 == 0) {
            
        }
    }
};

int main() {
    vector<int> nums1{1,3}, nums2{2};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}