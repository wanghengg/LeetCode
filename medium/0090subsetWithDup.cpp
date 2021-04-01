#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(bool choosePre, int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        dfs(false, cur + 1, nums);
        if (!choosePre && cur > 0 && nums[cur - 1] == nums[cur]) {
            return;
        }
        t.push_back(nums[cur]);
        dfs(true, cur + 1, nums);
        t.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        dfs(false, 0, nums);
        return ans;
    }
};


int main() {
    vector<int> nums{4,4,4,1,4};
    Solution solution;
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    for (auto& line : result) {
        for (auto& iter : line) {
            cout << iter << ' ';
        }
        cout << endl;
    }
    return 0;
}