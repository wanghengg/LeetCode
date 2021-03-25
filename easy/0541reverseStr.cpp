#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
    string reverseStr(string s, int k) {
        int len = s.size();
        int left = 0;
        int right = left + 2 * k - 1;
        while (right < len) {
            reverse(s, left, left + k - 1);
            left += 2 * k;
            right += 2 * k;
        }
        if (left + k >= len) {
            reverse(s, left, len - 1);
        } else {
            reverse(s, left, left + k - 1);
        }

        return s;
    }
};