//
// Created by wangheng on 2021/4/10.
//

#include <bits/stdc++.h>
using namespace std;

// 递归写法
class Solution{
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0) {
            return false;
        }
        if (n % 2 == 0) {
            n /= 2;
        } else if (n % 3 == 0) {
            n /= 3;
        } else {
            n /= 5;
        }
        return isUgly(n);
    }
};

// 非递归方式
class Solution1{
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        int factors[3] = {2,3,5};
        for (auto& factor : factors) {
            while (n % factor == 0) {
                n /= factor;
            }
        }
        return n == 1;
    }
};

int main() {
    Solution solution;
    int n = 0;
    cout << boolalpha << solution.isUgly(n) << endl;
    return 0;
}