//
// Created by wangheng on 2020/6/1.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

// 使用双指针
class Solution1{
public:
    int lengthOfLongestSubstring(string s) {
        auto first = s.begin();
        auto second = first + 1;
        int res = 0;
        while (first != s.end()) {
            while (second != s.end() && find(first, second, *second) == second)
                ++second;
            res = (second - first > res) ? (int)(second - first) : res;
            ++first;
        }
        return res;
    }
};

// 滑动窗口
class Solution2{
public:
    int lengthOfLongestSubstring(string s) {
        // hash集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

int main() {
    string s{"pwwkew"};
    Solution2 solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}