#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution{
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;

    }
};