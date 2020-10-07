#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto& iter : nums) {
            count[iter]++;
            if (count[iter] > 1)
                return iter;
        }
        return nums[0];
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2,3,1,0,2};
    cout << solution.findRepeatNumber(nums) << endl;
    return 0;
}