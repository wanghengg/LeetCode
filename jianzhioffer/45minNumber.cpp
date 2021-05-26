//
// Created by wangheng on 2021/4/18.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string minNumber(vector<int>& nums) {
        vector<string> data(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            data[i] = to_string(nums[i]);
        }
        sort(data.begin(), data.end(), [] (string first, string second) {return first + second < second + first;});
        string result;
        for(auto& iter : data) {
            result += iter;
        }
        return result;
    }
};