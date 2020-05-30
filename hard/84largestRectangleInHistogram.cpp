//
// Created by wangheng on 2020/5/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/*
 * 暴力解法，时间复杂度为O(n)，空间复杂度为O(1)
 * 通过96/95个测试，最后一个测试超出时间限制
 */
class Solution1{
public:
    int largestRectangleArea(vector<int>& heights) {
        int height, result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            height = heights[i];
            for (int j = i; j < heights.size(); ++j) {
                height = (height < heights[j]) ? height : heights[j];
                int area = (j - i + 1) * height;
                result = (result > area) ? result : area;
            }
        }
        return result;
    }
};

// 算法正确，通过全部测试用例，但是时间超时
class Solution2{
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        vector<int>::reverse_iterator left;
        vector<int>::iterator right;
        for (auto height = heights.begin(); height != heights.end();) {
            left = find_if(vector<int>::reverse_iterator(height), heights.rend(),
                    [height](int x) {return x < *height;});
            right = find_if(height+1, heights.end(),
                    [height](int x) {return x < *height;});
            int area = (int)((left - vector<int>::reverse_iterator(right))) * (*height);
            result = (result > area) ? result : area;
            height = find_if_not(height+1, heights.end(),
                    [height](int x){return *height == x;});
        }
        return result;
    }
};

class Solution3{
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
                mono_stack.pop();
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
                mono_stack.pop();
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);

        return ans;
    }
};

int main() {
    Solution2 solution;
    vector<int> heights{1,1,1,1,1,1,1,1,19,1,1,1,1,1,1,1,1,8,6,1,1,1,2,4};
    cout << solution.largestRectangleArea(heights) << endl;

    return 0;
}