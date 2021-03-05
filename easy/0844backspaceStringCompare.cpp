#include <iostream>
#include <string>
using namespace std;

// 使用栈，当出现'#'且栈不为空时从栈顶弹出一个元素，当为其他字符时直接压入栈，最后比较两个栈保存的字符串是否相等
class Solution{
public:
    bool backspaceCompare(string S, string T) {
        string str1, str2;
        for(auto &iter: S) {
            if (iter == '#') {
                if (!str1.empty()) {
                    str1.pop_back();
                }
            } else {
                str1.push_back(iter);
            }
        }
        for (auto& iter: T) {
            if (iter == '#') {
                if (!str2.empty()) {
                    str2.pop_back();
                }
            } else {
                str2.push_back(iter);
            }
        }
        return str1 == str2;
    }
};

int main() {
    string S = "y#fo##f", T = "y#f#o##f";
    Solution solution;
    cout << boolalpha << solution.backspaceCompare(S, T);
    return 0;
}