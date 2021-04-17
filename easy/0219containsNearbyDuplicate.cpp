//
// Created by wangheng on 2021/4/17.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> count;
        for(int i = 0; i < nums.size(); ++i) {
            if (count.count(nums[i])) {
                for(auto& iter : count[nums[i]]) {
                    if (i - iter <= k)
                        return true;
                }
            }
            count[nums[i]].emplace_back(i);
        }
        return false;
    }
};

class Solution1{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> count;
        for(int i = 0; i < nums.size(); ++i) {
            if (count.count(nums[i])) {
                return true;
            }
            count.insert(nums[i]);
            if (count.size() > k) {
                count.erase(nums[i-k]);
            }
        }
        return false;
    }
};