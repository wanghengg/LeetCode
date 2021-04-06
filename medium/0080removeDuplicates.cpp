#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 0;  // 最多重复2次
        int i = 0, j = 0;
        while (j < nums.size() - 1) {
            if (count < 2) {
                nums[i++] = nums[j];
                ++count;
                if (nums[j] != nums[j+1]) {
                    count = 0;
                }
                ++j;
            } else {
                while (j < nums.size() && nums[j] == nums[j-1]) {
                    ++j;
                }
                count = 0;
            }
        }
        if (j == nums.size() - 1 && count < 2) nums[i++] = nums[j];
        return i;
    }
};

// 更简明的写法
class Solution1{
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow-2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int main() {
    Solution1 solution;
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    cout << solution.removeDuplicates(nums) << endl;
    return 0;
}