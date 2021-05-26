//
// Created by wangheng on 2021/4/18.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> data;
        for(auto& iter : nums) {
            data[iter]++;
        }
        int result = 0;
        for(auto iter = data.begin(); iter != data.end(); ++iter) {
            if (iter->second == 1)
                result = iter->first;
        }
        return result;
    }
};