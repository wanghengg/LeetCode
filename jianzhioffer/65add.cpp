//
// Created by wangheng on 2021/4/18.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int add(int a, int b) {
        if (b == 0) {
            return a;
        }
        // a^b是非进位和（不包含进位），(a&b)<<1是进位，对负数不能直接移位，所以应该先强制类型转换为无符号数
        return add(a ^ b, (unsigned int)(a & b) << 1);
    }
};

int main() {
    Solution solution;
    int a = -1787, b = 2;
    cout << solution.add(a, b) << endl;
    return 0;
}