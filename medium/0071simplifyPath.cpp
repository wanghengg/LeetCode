//
// Created by wangheng on 2021/6/5.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> split_path;
        int len = path.size();
        string word;
        for(int i = 0; i < len; ++i) {
            if (path[i] == '/') {
                if (!word.empty()) {
                    if (word == "..") {
                        if (!split_path.empty())
                            split_path.pop();
                    } else {
                        if (word != ".")
                            split_path.emplace(word);
                    }
                    word.clear();
                }
                continue;
            }
            word += path[i];
        }
        stack<string> res;
        while (!split_path.empty()) {
            res.emplace(split_path.top());
            split_path.pop();
        }
        string result = "/";
        while (!res.empty()) {
            result += res.top();
            result += "/";
            res.pop();
        }
        return result == "/" ? result : result.substr(0, result.size()-1);
    }
};

int main() {
    string path = "/a//b////c/d//././/..";
    Solution solution;
    cout << solution.simplifyPath(path) << endl;
    return 0;
}