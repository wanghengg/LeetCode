//
// Created by wangheng on 2021/4/19.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int sum(int a, int b) {
        if (b == 0) return a;
        return sum(a^b, (a&b)<<1);
    }
    int sumNums(int n) {
        if (n == 1) return 1;
        return sum(sumNums(n-1), n);
    }
};

int main() {
    Solution solution;
    cout << solution.sumNums(10000) << endl;
    return 0;
}