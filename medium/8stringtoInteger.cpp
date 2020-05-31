//
// Created by wangheng on 2020/5/31.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    int myAtoi(string str) {
        auto first = find_if_not(str.begin(), str.end(),
                [](char c) {return c == ' ';});
        if (!isdigit(*first) && *first != '+' && *first != '-')
            return 0;
        auto last = find_if_not(first+1, str.end(),
                [](char c) {return isdigit(c);});
        auto sub = str.substr(first-str.begin(), last-first);
        int i = 0;
        if (sub.front() == '+' || sub.front() == '-')
            i = 1;
        int flag = (sub.front() == '-') ? -1 : 1;
        long long res = 0;
        for (; i < sub.size(); ++i) {
            res = res * 10 + sub[i] - '0';
            if (res > INT_MAX && flag == 1)
                return INT_MAX;
            if (res > INT_MAX && flag == -1)
                return INT_MIN;
        }
        return flag * res;
    }
};

int main() {
    Solution solution;
    cout << solution.myAtoi("  -42") << endl;

    return 0;
}