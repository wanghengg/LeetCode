//
// Created by wangheng on 2020/5/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using std::string;
using std::vector;
using std::stoi;
using std::reverse;
using std::isdigit;
using std::isalpha;

/*
 * 使用栈操作解题，当遇到数字和左括号'['时进栈，若遇到有括号']'，则开始出栈直至出栈遇到左括号'['，
 * 左括号'['出栈之后，栈顶元素一定是当前sub对应的字符串出现的次数，将得到的重复n次的字符串后重新
 * 压入栈，重复上述操作直至到达字符串结尾。
 */
class Solution1{
public:
    string getDigits(string& s, size_t &ptr) {
        string ret = "";
        // 如果多个数字连续出现，可以一次读取连续数字段
        while (isdigit(s[ptr]))
            ret.push_back(s[ptr++]);
        return ret;
    }

    string getString(vector<string> &v) {
        string ret;
        for (const string& iter : v)
            ret += iter;
        return ret;
    }
    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if(isalpha(cur) || cur == '[') {
                // 获取一个字母进栈
                stk.push_back(string(1, s[ptr++]));
            } else {
                ++ptr;
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                // 将出栈的字母倒序
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前sub对应的字符串应该出现的次数
                int times = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                while (times--)
                    t += o;
                // 将构造好的字符串进栈
                stk.push_back(t);
            }
        }
        return getString(stk);
    }
};

/*
 * 递归解法，采用分治的思想，解析外层括号之前，先解析内层括号。
 * 假如该字符串中存在左括号“[”,当碰到左括号"["时，重复上一步骤；
 * 假如该字符串中不存在“[”了，那么下一个碰到的一定是右括号“]”,
 * 当碰到右括号“]”,说明以上一个左括号“[”开头的字符到此结束，
 * 只需要记录该字符串然后再乘以“[”前的数字即可。
 */
class Solution2{
public:
    string analysis(string s, int& index) {
        string res;
        int num = 0;
        string temp;
        while (index < s.size()) {
            if (s[index] >= '0' && s[index] <= '9') {
                num = 10 * num + s[index] - '0';
            } else if (s[index] == '[') {
                temp = analysis(s, ++index);
                while (num--)
                    res += temp;
                num = 0;
            } else if (s[index] == ']')
                break;
            else
                res += s[index];
            ++index;
        }
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return analysis(s, index);
    }
};

int main() {
    Solution2 solution;
    std::cout << solution.decodeString("ef3[2[c4[p]10[bg]ef]3[mn]]") << std::endl;

    return 0;
}