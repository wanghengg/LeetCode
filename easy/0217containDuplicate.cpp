//
// Created by wangheng on 2021/4/17.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto& iter : nums) {
            count[iter]++;
            if (count[iter] == 2) {
                return true;
            }
        }
        return false;
    }
};

class Solution1{
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> count;
        for(auto& iter : nums) {
            if (count.count(iter)) {
                return true;
            }
            count.insert(iter);
        }
        return false;
    }
};