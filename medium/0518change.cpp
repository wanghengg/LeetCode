#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    set<multiset<int>> methods;
    multiset<int> method;

    void traceback(int amount, vector<int>& coins) {
        if (amount == 0) {
            methods.insert(method);
            method.clear();
            return;
        }
        for (auto& coin : coins) {
            if (amount - coin < 0) continue;
            method.insert(coin);
            traceback(amount - coin, coins);
        }
    }
    int change(int amount, vector<int>& coins) {
        traceback(amount, coins);
        return methods.size();
    }
};

class Solution1{
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;  // 总金额为0，只有0一种找零方法，所以base case为1
        for (auto& coin : coins) {  // 先遍历coins，避免重复
            for (int j = coin; j <= amount; ++j) {
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution1 solution;
    vector<int> coins{1,2,5};
    int amount = 5;
    cout << solution.change(amount, coins) << endl;
    return 0;
}