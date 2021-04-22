//
// Created by wangheng on 2021/4/22.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;
        int left = 0, right = 1, start = 0;
        int len = chars.size();
        while (right < len) {
            while (right < len && chars[right] == chars[left]) {
                ++right;
            }
            chars[start++] = chars[left];
            if (right - left > 1) {
                string copies = to_string(right - left);
                int index = 0;
                while (index < copies.size()) {
                    chars[start++] = copies[index++];
                }
            }
            left = right;
            right = right + 1;
        }
        if (left == chars.size()-1) chars[start++] = chars[left];
        return start;
    }
};

int main() {
    Solution solution;
    vector<char> chars{'a', 'b', 'c'};
    cout << solution.compress(chars) << endl;
    return 0;
}