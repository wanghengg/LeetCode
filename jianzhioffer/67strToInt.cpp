//
// Created by wangheng on 2021/4/23.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int strToInt(string str) {
        if (str.empty()) return 0;  // 字符串为空
        int start = 0;
        int len = str.size();
        while (start < len && str[start] == ' ') {  // 遇到空格往后移动start
            ++start;
        }
        if (start == len) return 0; // 字符串只包含空白字符
        if (!isdigit(str[start]) && str[start] != '+' && str[start] != '-') {
            return 0;
        }
        int flags;
        if (isdigit(str[start]) || str[start] == '+') flags = 1;
        if (str[start] == '-') flags = -1;
        int end = start + 1;
        while (end < len && isdigit(str[end])) {
            ++end;
        }
        long long result = 0;
        if (isdigit(str[start])) {
            result = result * 10 + (str[start] - '0');
        }
        ++start;    // start已经判断是否为符号位，所以++start
        while (start < end) {
            result = result * 10 + (str[start++] - '0');
            if (result > INT_MAX && flags == 1) return INT_MAX;
            if (result > INT_MAX && flags == -1) return INT_MIN;
        }
        return flags * result;
    }
};

int main() {
    Solution solution;
    string str{"-91283472332"};
    cout << solution.strToInt(str) << endl;
    return 0;
}