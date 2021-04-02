#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // flags用于表示已选的digit是否全部为0，是为true
    void traceback(int& count, int n, int times, set<int> digits) {
        if (times == n) {
            ++count;
            return;
        }
        if (times == 0) {
            for (int i = 1; i <= 9; ++i) {
                digits.insert(i);
                traceback(count, n, times + 1, digits);
                digits.erase(i);
            }
        } else {
            for (int i = 0; i <= 9; ++i) {
                if (digits.count(i)) {
                    continue;
                }
                digits.insert(i);
                traceback(count, n, times + 1, digits);
                digits.erase(i);
            }
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        int count = 0;
        set<int> digits;
        traceback(count, n, 0, digits);
        return count;
    }
};

int main() {
    int n = 2;
    Solution solution;
    cout << solution.countNumbersWithUniqueDigits(n) << endl;
    return 0;
}