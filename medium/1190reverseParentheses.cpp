//
// Created by wangheng on 2021/5/27.
//

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution{
public:
    string reverseParentheses(string s) {
        string res;
        stack<char> characters;
        for(auto& iter : s) {
            if (iter != ')') {
                characters.emplace(iter);
            } else {
                string tmp = "";
                while (characters.top() != '(') {
                    tmp.push_back(characters.top());
                    characters.pop();
                }
                characters.pop();
                for(auto& item : tmp) {
                    characters.emplace(item);
                }
            }
        }
        while (!characters.empty()) {
            res.push_back(characters.top());
            characters.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;
    string s = "a(bcdefghijkl(mno)p)q";
    cout << solution.reverseParentheses(s) << endl;
    return 0;
}