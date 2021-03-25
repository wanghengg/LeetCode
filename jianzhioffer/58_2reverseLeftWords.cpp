#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+ len - n);
        reverse(s.begin()+ len - n, s.end());
        return s;
    }
};