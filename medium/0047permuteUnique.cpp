#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    set<vector<int>> result;
    vector<int> track;
    void traceback(vector<int>& nums, vector<bool>& visited) {
        if (track.size() == nums.size()) {
            result.insert(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                track.emplace_back(nums[i]);
                visited[i] = true;
                traceback(nums, visited);
                track.pop_back();
                visited[i] = false;
            } else {
                continue;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        traceback(nums, visited);
        vector<vector<int>> res;
        for (auto& iter : result) {
            res.emplace_back(iter);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,1,3};
    vector<vector<int>> result = solution.permute(nums);
    for (auto& item : result) {
        for (auto& iter : item) {
            cout << iter << ' ';
        }
        cout << endl;
    }
    return 0;
}