#include <bits/stdc++.h>
using namespace std;


// 回溯算法
class Solution{
public:
    void traceback(vector<string>& result, string s, string option, vector<bool>& visited) {
        if (option.size() == s.size()) {
            result.emplace_back(option);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (!visited[i]) {  // 访问未访问过的元素
                option.push_back(s[i]);
                visited[i] = true;
                traceback(result, s, option, visited);
                option.pop_back();  // 回溯
                visited[i] = false;
            } else {    // 已经访问过，直接下一个
                continue;
            }
        }
    }
    vector<string> permutation(string s) {
        vector<string> result;
        string option;
        vector<bool> visited(s.size(), false);
        traceback(result, s, option, visited);
        sort(result.begin(), result.end());
        auto position = unique(result.begin(), result.end());
        return vector<string>(result.begin(), position);
    }
};

int main() {
    vector<string> result;
    Solution solution;
    string s{"aab"};
    result = solution.permutation(s);
    for (auto& iter : result) {
        cout << iter << endl;
    }
    return 0;
}