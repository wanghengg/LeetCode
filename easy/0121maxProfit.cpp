#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // 用minPrice保存到当前天的最小买入价格
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            profit = max(prices[i] - minPrice, profit);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};