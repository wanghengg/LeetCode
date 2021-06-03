//
// Created by wangheng on 2021/6/3.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> numbers(n+1, vector<int> {0, 0});
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                numbers[i+1][0] = numbers[i][0] + 1;
                numbers[i+1][1] = numbers[i][1];
            } else {
                numbers[i+1][0] = numbers[i][0];
                numbers[i+1][1] = numbers[i][1] + 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (numbers[i][0] - numbers[j][0] == numbers[i][1] - numbers[j][1]) {
                    ans = max(ans, i - j);
                }
            }
        }
        return ans;
    }
};

class Solution1{
public:
    // 假设nums[i...j]子数组0和1的个数相等，说明nums[0...i]中0的个数与1的个数之差等于nums[0...j]中0的个数与1的个数之差
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> preNumbers; // nums[0...i]中0的个数与1的个数之差对应的下标
        preNumbers.insert({0, -1});  // 还没有开始遍历nums时0和1的个数都是0
        int ans = 0;
        int n = nums.size();
        int preNumOf_0 = 0;
        int preNumOf_1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                preNumOf_0 += 1;
            } else {
                preNumOf_1 += 1;
            }
            int diff = preNumOf_0 - preNumOf_1;
            if (preNumbers.count(diff)) {
                ans = max(ans, i - preNumbers[diff]);
            } else {
                preNumbers[diff] = i;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{0, 1};
    Solution1 solution;
    cout << solution.findMaxLength(nums) << endl;

    return 0;
}