//
// Created by wangheng on 2021/4/18.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
    map<int, int> statistics;
    int times = 0;
public:
    void backtrack(int n, int total) {
        if (n == 0) {
            statistics[total]++;
            ++times;
            return;
        }
        for(int i = 1; i <= 6; ++i) {
            total += i;
            --n;
            backtrack(n, total);
            total -= i;
            ++n;
        }
    }
    vector<double> dicesProbability(int n) {
        int total = 0;
        backtrack(n, total);
        vector<double> result;
        for(auto& iter : statistics) {
            result.emplace_back(double(iter.second) / times);
        }
        return result;
    }
};

// 动态规划
class Solution1{
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0/6);    // 只有一个骰子点数和的概率
        for(int i = 2; i <= n; ++i) {
            // n个骰子点数之和的范围为[n, 6n]，所以一共有(6n-n+1)=5n+1中可能
            /*
             * https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/jian-zhi-offer-60-n-ge-tou-zi-de-dian-sh-z36d/
             */
            vector<double> tmp(5*i+1, 0);
            for(int j = 0; j < dp.size(); ++j) {
                for(int k = 0; k < 6; ++k) {
                    tmp[j+k] += dp[j] / 6.0;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};

int main() {
    Solution solution;
    vector<double> result = solution.dicesProbability(10);
    for(auto& iter : result) {
        cout << iter << ' ';
    }
    return 0;
}