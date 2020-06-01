//
// Created by wangheng on 2020/6/1.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 使用双指针
class Solution{
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

int main() {
    string s{"pwwkew"};
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}