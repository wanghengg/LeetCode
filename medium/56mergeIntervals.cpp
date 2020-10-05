#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) {return v1[0] < v2[0];});
        vector<vector<int>> result = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                if (result.back()[1] < intervals[i][1]) {
                    result.back()[1] = intervals[i][1];
                }
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,2}, {2,11}, {8,10}, {15,18}};
    Solution solution;
    vector<vector<int>> result = solution.merge(intervals);
    for (auto& item : result) {
        for (auto& iter : item) {
            cout << iter << ' ';
        }
        cout << endl;
    }

    return 0;
}