#include <iostream>
using namespace std;

// 暴力解法，用减法代替除法，超时
class Solution{
public:
    int divide(int dividend, int divisor) {
        bool positive = true;
        if ((dividend ^ divisor) & 0x80000000) {
            positive = false;
        }
        long long first = abs((long long)dividend);
        long long second = abs((long long)divisor);
        int res = 0;
        while (first >= second) {
            res++;
            first -= second;
        }
        if (positive) {
            return res;
        } else {
            return -res;
        }
    }
};

class Solution1{
public:
    int divide(int dividend, int divisor) {
        bool positive = true;
        if ((dividend ^ divisor) & 0x80000000) {
            positive = false;
        }
        long long first = abs((long long)dividend);
        long long second = abs((long long)divisor);
        long long tmp = second;
        if (first < second) return 0;
        long long times = 1, res = 0;
        while (first >= (second << 1)) {    // 每次除数翻倍，直至大于被除数
            times <<= 1;
            second <<= 1;
            res += times;
            first -= second;
        }
        while (second >= tmp) {
            while (second >= tmp && first < second) {   // 除数减半，直至被除数大于等于除数，除数减半的同时times也减半
                times >>= 1;
                second >>= 1;
            }
            while (second >= tmp && first >= second) {  // 最后被除数小于除数，但是此时除数可能仍然大于tmp(最开始的除数)
                res += times;
                first -= second;
                second >>= 1;
                times >>= 1;
            }
        }
        if (positive) {
            if (res > INT_MAX) return INT_MAX;
            return res;
        } else {
            return -res;
        }
    }
};

int main() {
    Solution1 solution;
    cout << solution.divide(2147483647, 3) << endl;
    return 0;
}
