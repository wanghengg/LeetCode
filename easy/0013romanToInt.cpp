//
// Created by wh969 on 2021/6/14.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
     * 一般情况下小的数字在打的数字右边，直接累加即可
     * 如果出现小的数字在打的数字左边，根据规则减去小的数字即可，例如XIV可视为X-I+V = 10 - 1 + 5 = 14
     */
    int romanToInt(string s) {
        unordered_map<char, int> char2num{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                    {'C', 100}, {'D', 500}, {'M', 1000}};
        int len = s.size();
        int result = 0;
        for (int i = 0; i < len; ++i) {
            int value = char2num[s[i]];
            if (i < len-1 && value < char2num[s[i+1]]) {
                result -= value;
            } else {
                result += value;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "XIV";
    cout << solution.romanToInt(s) << endl;
    return 0;
}