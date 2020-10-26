#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return {0};
        vector<int> tmp = nums; // 用于保存未排序的nums
        sort(nums.begin(), nums.end()); // 对nums排序
        unordered_map<int, int> numbers{{nums[0], 0}};
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                numbers[nums[i]] = i;   // 排序后，小于nums[i]的元素个数等于其第一次出现时的下标i
            }
        }
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            result[i] = numbers[tmp[i]];
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums{8,1,2,2,3};
    vector<int> result = solution.smallerNumbersThanCurrent(nums);
    for(auto& it : result) {
        cout << it << ' ';
    }
    return 0;
}