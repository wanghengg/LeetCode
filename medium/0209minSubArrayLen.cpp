#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minSubArray(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int count = 0;
        int minLen = nums.size();
        for (; right < nums.size(); ++right) {
            count += nums[right];
            if (count >= target) {
                while (count >= target) {
                    count -= nums[left];
                    ++left;
                }
                --left;
                count += nums[left];
                minLen = (right - left + 1 < minLen) ? right - left + 1 : minLen;
            }
        }
        if (count < target) return 0;
        return minLen;
    }
};

int main() {
    Solution solution;
    vector<int> nums{5,1,3,5,10,7,4,9,2,8};
    int target = 15;
    cout << solution.minSubArray(target, nums) << endl;
    return 0;
}