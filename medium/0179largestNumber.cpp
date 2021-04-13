//
// Created by wh969 on 2021/4/12.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            strNums[i] = to_string(nums[i]);
        }
        // 要保证最终的字符串最大，既要保证每次拼接的字符串最大，首位较大的字符串较大
        sort(strNums.begin(), strNums.end(),
             [](const string& first, const string& second) {return first + second > second + first;});
        if (strNums.front() == "0") return "0"; // 如果开头第一个字符串就是0，即最大数字为0，则直接返回"0"
        string result;
        for(auto& iter : strNums) {
            result += iter;
        }
        return result;
    }
};