#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mark;
        int i;
        for (i = 0; i < nums.size(); ++i) {
            mark[nums[i]]++;
            if (mark[nums[i]] > nums.size() / 2) {
                break;
            }
        }
        return nums[i];
    }
};

// 摩尔投票法
class Solution1{
public:
    int majorityElement(vector<int>& nums) {
        /*
         * x是假设的众数，如果遍历中元素和众数x相等，vote加1，否则vote减1
         * 由于众数大于数组长度的一半，所以最终vote大于0
         * 如果遍历到位置a时vote等于0，说明[0,a]中众数和非众数各有一半，剩余的n-a个数字中的众数仍然为x
         */
        int x = 0, vote = 0;
        for (auto& iter : nums) {
            if (vote == 0) {
                x = iter;   // 每次假设剩余的数字中的第一个为众数
            }
            vote += (iter == x) ? 1 : -1;
        }
        return x;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << solution.majorityElement(nums) << endl;

    return 0;
}