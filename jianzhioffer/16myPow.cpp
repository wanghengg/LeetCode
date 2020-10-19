#include <iostream>
using namespace std;

// 递归解法
class Solution{
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        long b = n;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }
        if (n == 0) return 1;
        return (b % 2 == 1) ? x * myPow(x * x, b / 2) : myPow(x * x, b / 2);
    }
};

// 非递归迭代计算方法
class Solution1{
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        long b = n;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }
        if (n == 0) return 1;
        double res = 1.0;
        while (b > 0) {
            if ((b & 1) == 1) res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};

int main() {
    Solution1 solution;
    cout << solution.myPow(2.0, 10) << endl;

    return 0;
}