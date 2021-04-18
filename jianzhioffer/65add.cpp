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
        return add(a ^ b, (unsigned int)(a & b) << 1);
    }
};

int main() {
    Solution solution;
    int a = -1787, b = 2;
    cout << solution.add(a, b) << endl;
    return 0;
}