//
// Created by wangheng on 2021/5/31.
//

#include <iostream>
using namespace std;

class Solution{
public:
    bool isPowerOfFour(int n) {
        if (n > 0 && (n & (n-1)) == 0) {    // n大于0并且其二进制只能包含一位1
            while (n > 1) { // 大于1时每次右移两位，直到小于等于1（0或者1）
                n >>= 2;
            }
            if (n == 1) return true;    // 等于1说明是4的幂，否则不是
            else return false;
        }
        return false;
    }
};

int main() {
    Solution solution;
    int n = 5;
    cout << boolalpha << solution.isPowerOfFour(n) << endl;
    return 0;
}