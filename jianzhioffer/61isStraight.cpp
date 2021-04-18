//
// Created by wangheng on 2021/4/18.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isStraight(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int index = 0;
        int numberZero = 0;
        while (nums[index] == 0) {
            ++index;
            ++numberZero;
        }
        for(; index < nums.size() - 1; ++index) {
            int diff = nums[index+1] - nums[index];
            if (diff == 0) return false;
            if (diff == 1) continue;
            numberZero -= (diff-1);
        }
        return numberZero >= 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0,0,2,2,5};
    cout << solution.isStraight(nums) << endl;

    return 0;
}