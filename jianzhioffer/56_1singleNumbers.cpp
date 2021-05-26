//
// Created by wangheng on 2021/4/18.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> singleNumbers(vector<int>& nums) {
            int ret = 0;    // 将所有的数异或，最终结果为两个不同数的异或
            for (int n : nums)
                ret ^= n;
            int div = 1;    // 获得res中最低位的1，表示两个不同的数字在此位不同
            while ((div & ret) == 0)
                div <<= 1;
            int a = 0, b = 0;
            for (int n : nums)
                if (div & n)
                    a ^= n;
                else
                    b ^= n;
            return vector<int>{a, b};
        }
};