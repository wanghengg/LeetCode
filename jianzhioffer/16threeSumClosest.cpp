#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto first = 0;
        auto second = 3;
        int length = nums.size();
        int difference = abs(accumulate(nums.begin()+first, nums.begin()+second, 0) - target * 3);
        while (second <= length) {
            int value = accumulate(nums.begin()+first, nums.begin()+second, 0);
            if (abs(value - target * 3) < difference) {
                difference = abs(value - target * 3);
            }
        }
    }
};