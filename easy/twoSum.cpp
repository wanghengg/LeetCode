#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    for (auto first = nums.cbegin(); first != nums.cend(); ++first) {
        auto second = std::find(first + 1, nums.cend(), target - *first);
        if (second != nums.cend())
            return {static_cast<int>(first - nums.cbegin()), static_cast<int>(second - nums.cbegin())};
    }
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto result = twoSum(nums, target);
    for (auto iter : result)
        std::cout << iter << ' ';
    return 0;
}