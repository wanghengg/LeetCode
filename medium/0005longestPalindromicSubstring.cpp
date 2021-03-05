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
        // dp[i][j]用来表示字符串s的第i个字母到第j个字母组成的子串是否为回文串
        vector<vector<int>> dp(length, vector<int>(length));
        string result;
        // l表示j-i，即子串的长度减1
        for (int l = 0; l < length; ++l) {
            for (int i = 0; i + l < length; ++i) {
                int j = i + l;
                if (l == 0)
                    dp[i][j] = 1;   // i==j，子串长度为1时，肯定是回文串
                else if (l == 1)
                    dp[i][j] = (s[i] == s[j]);  // 子串长度为2时，两个字母相等才是回文串
                else
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                // s[i:j]是回文字符串且长度大于前一个回文串的长度
                if (dp[i][j] && result.size() < l + 1)
                    result = s.substr(i, l + 1);
            }
        }
        return result;
    }
};

// 中间扩展算法
class Solution3{
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left+1, right-1};
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto centerWithOne = expandAroundCenter(s, i, i);
            int left1 = centerWithOne.first;
            int right1 = centerWithOne.second;
            auto centerWithTwo = expandAroundCenter(s, i, i+1);
            int left2 = centerWithTwo.first;
            int right2 = centerWithTwo.second;
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// Manacher算法
class Solution4 {
public:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }

    string longestPalindrome(string s) {
        int start = 0, end = -1;
        string t = "#";
        for (char c: s) {
            t += c;
            t += '#';
        }
        t += '#';
        s = t;

        vector<int> arm_len;
        int right = -1, j = -1;
        for (int i = 0; i < s.size(); ++i) {
            int cur_arm_len;
            if (right >= i) {
                int i_sym = j * 2 - i;
                int min_arm_len = min(arm_len[i_sym], right - i);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            }
            else {
                cur_arm_len = expand(s, i, i);
            }
            arm_len.push_back(cur_arm_len);
            if (i + cur_arm_len > right) {
                j = i;
                right = i + cur_arm_len;
            }
            if (cur_arm_len * 2 + 1 > end - start) {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }

        string ans;
        for (int i = start; i <= end; ++i) {
            if (s[i] != '#') {
                ans += s[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution4 solution;
    cout << solution.longestPalindrome("eacaeb") << endl;
    string str1 = "hello";

    return 0;
}