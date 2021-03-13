#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution{
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() < k) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;

    }
};