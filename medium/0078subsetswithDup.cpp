#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
     * res用于存放结果
     * subset是子集
     */
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int index, vector<int> subset) {
        if (index == nums.size()) { // 终止条件，index到达和nums的元素大小一致，递归结束
            res.emplace_back(subset);
            return;
        }
        subset.emplace_back(nums[index]);   // 子集添加元素
        backtrack(res, nums, index + 1, subset);    // 递归
        subset.pop_back();  // 回溯，不添加nums[index]
        backtrack(res, nums, index + 1, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(res, nums, 0, subset);
        return res;
    }
};