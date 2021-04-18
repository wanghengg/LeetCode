//
// Created by wangheng on 2021/4/18.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniqueChar;
        int left = 0, right = 0;
        int result = INT_MIN;
        while (right < s.size()) {
            while (right < s.size() && uniqueChar.count(s[right]) == 0) {
                uniqueChar.insert(s[right++]);
            }
            result = max(result, right - left);
            while (left < right && uniqueChar.count(s[right])) {
                uniqueChar.erase(s[left++]);
            }
        }
        return result == INT_MIN ? 0 : result;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("dafa") << endl;

    return 0;
}