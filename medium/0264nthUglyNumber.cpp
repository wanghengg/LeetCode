//
// Created by wangheng on 2021/4/10.
//

#include <bits/stdc++.h>
using namespace std;

// 三指针
class Solution{
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; ++i) {
            int n2 = dp[a] * 2;
            int n3 = dp[b] * 3;
            int n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);
            if (dp[i] == n2) ++a;
            if (dp[i] == n3) ++b;
            if (dp[i] == n5) ++c;
        }
        return dp[n-1];
    }
};

// 最小堆
class Solution1{
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<>> minHeap;
        minHeap.push(1);
        int count = 0;
        long long top;
        while (count != n) {
            top = minHeap.top();
            minHeap.pop();
            ++count;
            minHeap.push(top * 2);
            minHeap.push(top * 3);
            minHeap.push(top * 5);
            while (!minHeap.empty() && minHeap.top() == top) {
                minHeap.pop();  // 如果有重复元素则删掉，12可能是6*2也可能是4*3
            }
        }
        return top;
    }
};

int main() {
    Solution1 solution;
    cout << solution.nthUglyNumber(1407) << endl;
    return 0;
}