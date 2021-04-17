//
// Created by wangheng on 2021/4/17.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
     * 根据题意，对于任意一个位置i（假设其值为u)，实际上我们的目标是查找在范围[max(0, i-k), i)内查找
     * 值范围在[u-t, u+t]的数
     */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> data;
        for(int i = 0; i < nums.size(); ++i) {
            auto iter = data.lower_bound(max(nums[i], INT_MIN+t) - t);
            if (iter != data.end() && *iter <= min(nums[i], INT_MAX-t) +t) {
                return true;
            }
            data.insert(nums[i]);
            if (i >= k) {
                data.erase(nums[i-k]);
            }
        }
        return false;
    }
};

int main() {
    Solution solution1;
    vector<int> nums{1,2,3,1};
    int k = 3;
    int t = 0;
    cout << solution1.containsNearbyAlmostDuplicate(nums, k, t) << endl;
    return 0;
}