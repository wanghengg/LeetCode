#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return;
        int i;
        for (i = length-1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {      // 从后往前按对比较
                int j = i + 1;
                /*
                 * 遇到一对相邻数，第二个数大于第一个，为了保证是下一个更大的排列，
                 * 往后找到大于第一个数的最小的数，然后交换二者的位置，并对第一个数的
                 * 后面的数组进行排序
                 */
                while (j < length && nums[j] > nums[i-1]) {
                    j++;
                }
                swap(nums[j-1], nums[i-1]);
                sort(nums.begin()+i, nums.end());
                break;
            }
        }
        if (i == 0) reverse(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> nums{2,4,3,1};
    Solution solution;
    solution.nextPermutation(nums);
    for(auto& iter : nums) {
        cout << iter << ' ';
    }
    return 0;
}