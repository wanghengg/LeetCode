//
// Created by wangheng on 2021/9/7.
//
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans = 0;
        int n = height.size();
        for(int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                int curWidth = i - left - 1;
                int curHeight = min(height[left], height[i]) - height[top];
                ans += curWidth * curHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};

class Solution1{
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans = 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = height.size() - 1;
        while(left < right) {
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};
