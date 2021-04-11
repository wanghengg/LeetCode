//
// Created by wangheng on 2021/4/11.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        int count = 0;
        for (int i = 0; i < g.size(); ++i) {
            while (index < s.size() && s[index] < g[i]) {
                ++index;
            }
            if (index >= s.size()) {
                break;
            }
            ++count;
            ++index;
        }
        return count;
    }
};