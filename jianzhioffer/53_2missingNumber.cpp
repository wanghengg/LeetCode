#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int missingNumber(vector<int>& nums) {
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i)
                return i;
        }
        return i;
    }
};

int main() {
    Solution solution;
    vector<int> nums{};
    cout << solution.missingNumber(nums) << endl;
    return 0;
}