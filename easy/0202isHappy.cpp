#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> res;
        if (n == 1) return true;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            } else if (res.count(sum)) {
                return false;
            } else {
                res.insert(sum);
                n = sum;
            }
        }
    }
};