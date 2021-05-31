//
// Created by wangheng on 2021/5/30.
//

#include <iostream>
using namespace std;

class Solution{
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n > 0) {
            if (n != 1 && n % 2 != 0) return false;
            n /= 2;
        }
        return true;
    }
};

/*
 * 如果一个数是2的幂，那么它的二进制一定只有一个1，并且其为正整数
 * 判断一个数的二进制是否只有一个1的办法，n&(n-1)可以去掉最低位的1，如果去掉最低位的1
 * 后值为0说明这个数的二进制只有一个1
 */
class Solution1{
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && (n & (n-1)) == 0);
    }
};

int main() {
    Solution1 solution;
    int n = 4;
    cout << boolalpha << solution.isPowerOfTwo(n) << endl;
    return 0;
}