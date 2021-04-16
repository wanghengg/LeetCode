//
// Created by wangheng on 2021/4/14.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for(auto& iter : s1) {
            need[iter]++;
        }

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right++];
            // 对窗口内的数据进行更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid += 1;
                }
            }

            // 判断左侧窗口是否需要收缩
            // 最终滑动窗口内的元素个数应该和s1的元素个数相等，因为滑动窗口内的字符串应该是s1的排列
            // 所以当滑动窗口内的元素个数大于s1的元素个数时就应该收缩
            while (right - left >= s1.size()) {
                // 找到合法子串
                if (valid == need.size()) {
                    return true;
                }
                char d = s2[left++];
                // 进行窗口的更新
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};


class Solution1{
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for(auto& iter : s1) {
            need[iter]++;
        }

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right++];
            // 对窗口内的数据进行更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid += 1;
                }
            }

            while (valid == need.size()) {
                if (right - left == s1.size()) {
                    return true;
                }
                char d = s2[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};