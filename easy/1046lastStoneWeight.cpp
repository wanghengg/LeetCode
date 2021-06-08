//
// Created by wangheng on 2021/6/8.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (auto& iter : stones) {
            q.emplace(iter);
        }
        while (q.size() >= 2) {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            int diff = abs(first - second);
            q.emplace(diff);
        }
        if (q.empty()) {
            return 0;
        } else {
            return q.top();
        }
    }
};

int main() {
    vector<int> stones{2,7,4,1,8,1};
    Solution solution;
    cout << solution.lastStoneWeight(stones) << endl;
    return 0;
}