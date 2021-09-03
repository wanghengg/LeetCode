//
// Created by wangheng on 2021/9/3.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int first = 0; first < n-2; ++first) {
            int second = first + 1, third = n - 1;
            while (second < third && nums[first] + nums[second] <= nums[third]) {
                second++;
            }
            res += third - second;
        }
        return res;
    }
};