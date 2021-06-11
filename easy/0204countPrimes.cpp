//
// Created by wh969 on 2021/6/11.
//

#include <bits/stdc++.h>
using namespace std;

// 时间复杂度太高
class Solution{
public:
    bool isPrime(int number) {
        int a = floor(sqrt(number));
        for (int i = 2; i <= a; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int count = 0;
        for(int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                ++count;
            }
        }
        return count;
    }
};

// 埃氏筛
class Solution1{
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long )i*i < n) {
                    for (int j = i * i; j < n; j+=i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution2 solution;
    int n = 499979;
    cout << solution.countPrimes(n) << endl;
    return 0;
}