#include <iostream>
using namespace std;

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

int main() {
    Solution solution;
    cout << solution.myPow(2.0, 10) << endl;

    return 0;
}