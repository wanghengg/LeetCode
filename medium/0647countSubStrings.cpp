//
// Created by wangheng on 2021/4/12.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        int dp[s.size()][s.size()]; // dp[i][j]表示字符串[i,j]的子串能否构成回文子串
        memset(dp, 0, sizeof(sizeof(int)*s.size()*s.size()));
        for(int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
        }
        for (int i = 1; i < s.size(); ++i) {
            for (int j = 0; j + i < s.size(); ++j) {
                if (i == 1) {
                    if (s[j] == s[j+i]) {
                        dp[j][j+i] = 1;
                    }
                } else {
                    dp[j][j+i] = dp[j+1][j+i-1] && (s[j] == s[j+i]);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (dp[i][j] == 1) {
                    result += 1;
                }
            }
        }
        return result;
    }
};

class Solution1{
public:
    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < 2*n-1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution1 solution;
    string s{"fdsklf"};
    cout << solution.countSubstrings(s) << endl;

    return 0;
}