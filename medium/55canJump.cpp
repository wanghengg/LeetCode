#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        // 当前位置可以到达的最远的位置，当前位置是i，在当前位置能跳跃的最远距离是nums[i]，所以在当前位置能到达最远的地方时i + nums[i]
        int rightMost = 0;
        for (int i = 0; i < length; i++) {
            // 只有当前位置i小于最大位置时，才可以继续，否则最右位置rightMost小于i，那么到达rightMost之后没办法到达i
            if (i <= rightMost) {
                rightMost = max(rightMost, i + nums[i]);
                if (rightMost >= length - 1)    // 当rightMost大于length-1(也即是最右的位置)，则结束返回true
                    return true;
            }
        }
        return false;   // 如果最后能到达的位置还没有到达最右位置，返回false
    }
};

int main() {
    Solution solution;
    vector<int> nums{3,2,1,0,4};
    cout << boolalpha << solution.canJump(nums) << endl;
    return 0;
}