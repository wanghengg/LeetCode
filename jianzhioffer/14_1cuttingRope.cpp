#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
    int cuttingRope(int n) {
        if (n <= 3) return n-1;
        int a = n / 3;  // 根据计算推导，将绳子尽可能划分为长度为3的段，乘积最大
        int b = n % 3;
        if (b == 0) return pow(3, a);
        if (b == 1) return pow(3, a - 1) * 2 * 2;   // 如果余数为1，那么应该借用一个3和余数1组成2+2，因为2*2>3*1
        return pow(3, a) * b;
    }
};

class Solution1{
public:
    int cuttingRope(int n) {

    }
};

int main() {
    Solution solution;
    cout << solution.cuttingRope(3) << endl;
    return 0;
}