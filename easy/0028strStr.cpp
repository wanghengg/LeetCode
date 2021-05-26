//
// Created by wangheng on 2021/4/20.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int lenNeedle = needle.size();
        int len = haystack.size();
        for(int i = 0; i <= len - lenNeedle; ++i) {
            if (haystack.substr(i, lenNeedle) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    string haystack = "";
    string needle = "llo";
    cout << solution.strStr(haystack, needle) << endl;

    return 0;
}