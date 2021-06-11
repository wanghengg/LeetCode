//
// Created by wh969 on 2021/6/11.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i]);
        }
        int len = nums.size();
        for (int i = k; i < len; ++i) {
            if (q.top() < nums[i]) {
                q.pop();
                q.emplace(nums[i]);
            }
        }
        return q.top();
    }
};

int main() {
    Solution solution;
    vector<int> nums{3,2,1,5,6,4};
    int k = 2;
    cout << solution.findKthLargest(nums, k) << endl;
    return 0;
}