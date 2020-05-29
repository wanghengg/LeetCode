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

// Solution1不能通过全部测试，对于测试“ef3[c5[bg]ef]”错误
//class Solution1{
//public:
//    string decodeString(string s) {
//        string result;
//        string elem;    // inout的每个元素
//        int number = 0;
//        int count = 0;
//        vector<string> inout;
//        for (char i : s) {
//            if (i != ']') {
//                inout.emplace_back(1, i);
//                if (i == '[')
//                    ++count;
//            }
//            else {
//                string leastString;
//                while (count) {
//                    while ((elem = inout.back()) != "[") {
//                        leastString.append(elem);
//                        inout.pop_back();
//                    }
//                    --count;
//                    inout.pop_back();
//                    int base = 0;
//                    while (inout.back() >= "0" && inout.back() <= "9") {
//                        number = stoi(inout.back()) * (int)pow(10, base++) + number;
//                        inout.pop_back();
//                        if (inout.empty())
//                            break;
//                    }
//                    string temp = leastString;
//                    while (--number)
//                        leastString.append(temp);
//                }
//                while (!inout.empty()) {
//                    leastString.append(inout.back());
//                    inout.pop_back();
//                }
//                reverse(leastString.begin(), leastString.end());
//                result += leastString;
//            }
//        }
//        for (const string& iter : inout)
//            result += iter;
//        return result;
//    }
//};

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

int main() {
    Solution1 solution;
    std::cout << solution.decodeString("ef3[c5[bg]ef]11[leetcode]mn") << std::endl;

    return 0;
}