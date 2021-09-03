//
// Created by wangheng on 2021/9/3.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int first = 0; first < n - 2; ++first) {
            int second = first + 1, third = n - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum >= target) {
                    while (second < third && nums[third-1] == nums[third]) {
                        --third;
                    }
                    --third;
                }
                if (sum < target) {
                    res += (third - second);
                    ++second;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0, -4, -1, 1, -1, 2};
    int target = -5;
    cout << solution.threeSumSmaller(nums, target) << endl;
    return 0;
}