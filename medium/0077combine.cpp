//
// Created by wangheng on 2021/4/11.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> result;
    vector<int> possible;
    void backtrack(int n, int k, int cur, int count) {
        if (count == k) {
            result.emplace_back(possible);
            return;
        }
        if (n - cur + 1 + count > n) {  // 剪枝，cur到n之间的数加上count不够k个数
            return;
        }
        for (int i = cur; i <= n; ++i) {
            possible.emplace_back(i);
            ++count;
            backtrack(n, k, i + 1, count);
            --count;
            possible.pop_back();    // 回溯
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if (n < 1 || k <= 0 || k > n) return {};
        backtrack(n, k, 1, 0);
        return result;
    }
};