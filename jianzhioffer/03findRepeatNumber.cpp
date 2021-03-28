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

    int findRepeatNumber1(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                int temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[nums[i]] = temp;
            }
        }
        return false;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2,3,1,0,2};
    cout << solution.findRepeatNumber(nums) << endl;
    return 0;
}