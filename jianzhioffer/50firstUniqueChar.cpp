//
// Created by wh969 on 2021/4/9.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty()) return ' ';
        unordered_map<char, int> data;
        for(auto& iter : s) {
            data[iter]++;
        }
        char result = ' ';
        for (auto& iter : s) {
            if (data[iter] == 1) {
                result = iter;
                break;
            }
        }
        return result;
    }
};

int main() {
    string s{"hellohello"};
    Solution solution;
    cout << solution.firstUniqChar(s) << endl;

    return 0;
}