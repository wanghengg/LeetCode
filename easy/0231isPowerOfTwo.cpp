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

int main() {
    Solution solution;
    int n = 4;
    cout << boolalpha << solution.isPowerOfTwo(n) << endl;
    return 0;
}