#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 暴力解法，时间复杂度O(n^2)
class Solution1{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (auto first = nums.cbegin(); first != nums.cend(); ++first) {
            auto second = std::find(first + 1, nums.cend(), target - *first);
            if (second != nums.cend())
                return {static_cast<int>(first - nums.cbegin()), static_cast<int>(second - nums.cbegin())};
        }
        return {};
    }
};

// 利用hashmap求解
class Solution2{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        int size = nums.size();     // nums的元素个数
        for (int i = 0; i < size; ++i) {
            if (map.count(target - nums[i]) == 1)   // 找到target-nums[i]则返回
                return { map[target - nums[i]], i};
            map[nums[i]] = i;   // 否则将当前值插入map中
        }
        return {};
    }
};

int main() {
    std::vector<int> nums = {3,3,4};
    int target = 7;
    Solution2 solution;
    auto result = solution.twoSum(nums, target);
    for (auto iter : result)
        std::cout << iter << ' ';
    return 0;
}