//
// Created by wangheng on 2021/4/14.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (auto& iter : t) {
            need[iter]++;
        }
        int left = 0, right = 0;    // [left, right)
        int valid = 0;  // 记录键的个数
        int start = 0;
        int len = INT_MAX;  // 记录最小覆盖子串的起始索引及长度
        while (right < s.size()) {
            // c是将要移入窗口的字符
            char c = s[right];
            ++right;    // 右移窗口
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (valid == need.size()) {
                // 更新窗口长度
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];   // d是将要移出窗口的字符
                // 左移窗口
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    // 滑动窗里面字符d的个数可能大于need里面字符d的个数，此时直接减小window[d]，直到相等，valid减1，跳出循环
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};