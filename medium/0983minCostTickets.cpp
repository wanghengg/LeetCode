//
// Created by wangheng on 2021/4/11.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minCostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back()+1, 0);   // dp[i]表示到第i天所花的最少钱，dp[0] = 0
        unordered_map<int, int> tickets;
        tickets.emplace(1, costs[0]);
        tickets.emplace(7, costs[1]);
        tickets.emplace(30, costs[2]);
        int index = 0;
        for (int i = 1; i <= days.back(); ++i) {
            if (days[index] != i) { // 查看i是否在days中，如果不在dp[i] = dp[i-1]
                dp[i] = dp[i-1];
                continue;
            }
            int minTickets = INT_MAX;
            // 每天可以选择买三种票，截止当天所花的钱dp[i] = min(min(dp[i-1]+costs[0], dp[i-7]+costs[1]), dp[i-30]+costs[2])
            for (auto& iter : tickets) {
                if (i - iter.first >= 0) {  // 判断i-1/i-7/i-30是否大于等于0
                    minTickets = min(minTickets, dp[i - iter.first] + iter.second);
                } else {
                    minTickets = min(minTickets, dp[0] + iter.second); // 如果小于0.直接去dp[0]
                }
            }
            dp[i] = minTickets;
            index++;
        }
        return dp.back();
    }
};

int main() {
    Solution solution;
    vector<int> days{1,4,6,7,8,20};
    vector<int> costs{7,2,15};
    cout << solution.minCostTickets(days, costs) << endl;

    return 0;
}