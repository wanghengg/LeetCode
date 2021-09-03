//
// Created by wangheng on 2021/9/3.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int best = 10e7;
        for(int first = 0; first < n-2; first++) {
            if (first > 0 && nums[first] == nums[first-1]) continue;
            // 使用双指针枚举b和c
            int second = first + 1, third = n - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == target) return target;
                if (abs(sum - target) < abs(best - target)) {
                    best = sum;
                }
                if (sum > target) {
                    while (second < third && nums[third-1] == nums[third]) {
                        third--;
                    }
                    third--;
                } else {
                    while (second < third && nums[second+1] == nums[second]) {
                        second++;
                    }
                    second++;
                }
            }
        }
        return best;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-1,2,2,-4};
    int target = 1;
    cout << solution.threeSumClosest(nums, target) << endl;
    return 0;
}