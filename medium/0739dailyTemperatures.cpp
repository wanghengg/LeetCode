#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // 单调栈
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> stk;
        // 使用递增栈（按照出栈顺序大小划分 [1,2,3,4]是单调递减栈，[4,3,2,1]是单调递增栈）
        // 如果当前元素大于栈顶元素，这个元素就是第一个大于栈顶元素的值
        for(int i = 0; i < n; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};