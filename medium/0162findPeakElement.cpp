#include <iostream>
#include <vector>
using namespace std;

/*
 * 可以将nums数组中的任何给定序列看作交替的升序和降序序列，然后用二分法来查找所需要的峰值元素。
 * 将中点元素nums[mid]与其右元素对比，如果nums[mid]<nums[mid+1]，说明目前nums[mid]处于一个升序序列，
 * 则峰值在右侧，搜索空间缩小为mid的右侧（不包含mid），反之搜索空间缩小为mid左侧（包含mid）
 * 直到left==right，搜索结束
 */
class Solution{
public:
    int binarySearch(vector<int>& nums, int left, int right) {
        if (left == right) return left;
        int mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1]) {    // nums[mid]处于升序序列，搜索mid右边的序列
            return binarySearch(nums, mid+1, right);
        }
        return binarySearch(nums, left, mid);
    }
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums{3,2,3,1};
    Solution solution;
    cout << solution.findPeakElement(nums) << endl;

    return 0;
}