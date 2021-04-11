#include <bits/stdc++.h>
using namespace std;

// 复杂度太高，超时
class Solution{
public:
    // flags用于表示已选的digit是否全部为0，是为true
    void traceback(int& count, int n, int times, set<int> digits, bool flags) {
        if (times == n) {
            ++count;
            return;
        }
        for (int i = 0; i <= 9; ++i) {
            if (flags) {
                digits.clear();
            }
            if (digits.count(i)) {
                continue;
            }
            ++times;
            digits.insert(i);
            if (i != 0) flags = false;
            traceback(count, n, times, digits, flags);
            digits.erase(i);
            --times;
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        int count = 0;
        set<int> digits;
        traceback(count, n, 0, digits, true);
        return count;
    }
};

class Solution1{
public:
    int countNumbersWithUniqueDigits(int n) {
        int *dp = new int[n+1]; // dp[i]表示i位数字里面有重复位的个数
        memset(dp, 0, sizeof(int) * (n+1));
        for (int i = 2; i <= n; ++i) {
            // 如果前面i-1位有重复，那么最后一位任取一个数字都可以，所以是dp[i-1]*10
            // 如果前面i-1位无重复，那么前面i-1位无重复的数字个数为9 * pow(10, i-2) - dp[i-1]，其中由于
            // 首位不能为0，其他位可以为任意数字，所以i-1位所有组合为9 * pow(10, i-2)，其中重复的个数为dp[i-1]，
            // 所以不重复的个数为9 * pow(10, i-1) - dp[i-1]
            // 对于不重复的数字，最后一位必须是前面i-1位的任意一位才可能重复，所以*(i-1)
            dp[i] = dp[i-1] * 10 + (9 * pow(10, i-2) - dp[i-1]) * (i - 1);
        }
        int sum = 0;
        for (int i = 0; i <= n; ++i) {
            sum += dp[i];
        }
        return pow(10, n) - sum;
    }
};

int main() {
    int n = 3;
    Solution1 solution;
    cout << solution.countNumbersWithUniqueDigits(n) << endl;
    return 0;
}