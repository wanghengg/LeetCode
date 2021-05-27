//
// Created by wangheng on 2021/5/27.
//

#include <iostream>
using namespace std;

class Solution{
public:
    int hammingDistance(int x, int y) {
        int total = 0;
        int res = x ^ y;
        while (res != 0) {
            total += res & 0x1;
            res >>= 1;
        }
        return total;
    }
};