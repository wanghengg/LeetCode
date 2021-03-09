#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
    // 最终的结果对某个数取余等于每次计算取余
    int cuttingRope(int n) {
        if (n <= 3) return n-1;
        long long a = n / 3;
        long long b = n % 3;
        long long res;
        if (b == 1) {
            a -= 1;
            res = 4;
        } else if (b == 2) {
            res = 2;
        } else {
            res = 1;
        }
        while (a--) {
            res *= 3;
            res %= 1000000007;
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.cuttingRope(10) << endl;
    return 0;
}