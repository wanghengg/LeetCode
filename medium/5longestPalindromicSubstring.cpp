//
// Created by wangheng on 2020/5/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 暴力解法，时间复杂度O(n^3)
class Solution1{
public:
    string longestPalindrome(string s) {
        int length = s.size();
        string result;
        for (int i = 0; i < length; ++i) {
            for (int j = i; j < length; ++j) {
                string temp = string(s, i, j - i + 1);
                if (isPalindrome(temp) && result.size() < temp.size())
                    result = temp;
            }
        }
        return result;
    }

    bool isPalindrome(string& s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        return s == temp;
    }
};


// 动态规划方法
class Solution2{
public:
    string longestPalindrome(string s) {
        int length = s.size();
        vector<vector<int>> dp(length, vector<int>(length));
        string result;
        for (int l = 0; l < length; ++l) {
            for (int i = 0; i + l < length; ++i) {
                int j = i + l;
                if (l == 0)
                    dp[i][j] = 1;
                else if (l == 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if (dp[i][j] && result.size() < l + 1)
                    result = s.substr(i, l + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution2 solution;
    cout << solution.longestPalindrome("eacaeb") << endl;
    string str1 = "hello";

    return 0;
}