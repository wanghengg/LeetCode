//
// Created by wangheng on 2021/4/10.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target < 3) return {};
        int left = 1, right = 2;
        vector<int> possible{1,2};
        int sum = 3;
        vector<vector<int>> result;
        while (left < right) {
            if (sum == target) {
                result.emplace_back(possible);
                if (right - left == 1) break;
                ++left;
                ++right;
                sum = sum - (left - 1) + right;
                possible.erase(possible.begin());
                possible.emplace_back(right);
            } else if (sum < target) {
                ++right;
                sum += right;
                possible.emplace_back(right);
            } else {
                sum -= left;
                ++left;
                possible.erase(possible.begin());
            }
        }
        return result;
    }
};

int main() {
    int target = 9;
    Solution solution;
    vector<vector<int>> result = solution.findContinuousSequence(target);
    for (auto& item : result) {
        for (auto& iter : item) {
            cout << iter << ' ';
        }
        cout << endl;
    }
    return 0;
}