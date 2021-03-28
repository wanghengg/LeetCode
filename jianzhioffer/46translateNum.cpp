#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // 很显然，可以用递归
    int translateNum(int num) {
        if (num <= 9) return 1;
        if (num % 100 <= 25 && num % 100 >= 10) return translateNum(num / 100) + translateNum(num / 10);
        else return translateNum(num / 10);
    }
};