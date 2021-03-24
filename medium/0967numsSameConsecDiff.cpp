#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void dfs(int k, int n, int cur, vector<int>& result) {
        if (!n) {
            result.emplace_back(cur);
            return;
        }
        int digit = cur % 10;
        if (digit + k < 10)
            dfs(k, n-1, cur * 10 + digit + k, result);
        if (digit - k >= 0 && k)
            dfs(k, n-1, cur * 10 + digit - k, result);
    }


    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        if (n == 1) result.emplace_back(0);
        for (int i = 1; i <= 9; ++i) {
            dfs(k, n-1, i, result);
        }
        return result;
    }

    // 广度优先搜索
    vector<int> numsSameConsecDiff1(int n, int k) {
        deque<int> result{1,2,3,4,5,6,7,8,9};
        if (n == 1) result.push_front(0);
        while (--n) {   // 已经有第1位了，所以还需要循环n-1次，找到剩下n-1位
            int len = result.size();
            while (len--) {
                int front = result.front();
                result.pop_front();
                int cur = front % 10;
                if (cur+k < 10) result.push_back(front * 10 + cur + k);
                if (cur-k >= 0 && k) result.push_back(front * 10 + cur - k);    // 如果k为0，添加了重复元素
            }
        }
        return vector<int>(result.cbegin(), result.cend());
    }
};