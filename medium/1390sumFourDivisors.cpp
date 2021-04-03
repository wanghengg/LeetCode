#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
     * 关键在于怎么得到一个数的所有因数，实际上只需要循环到其平方根即可
     */
    set<int> getFactors(int n) {
        set<int> factors;
        int maxFactor = floor(sqrt(n));
        for (int i = 1; i <= maxFactor; ++i) {
            if (n % i == 0) {
                factors.insert(i);
                factors.insert(n / i);
            }
        }

        return factors;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (auto& iter : nums) {
            set<int> factors = getFactors(iter);
            if (factors.size() == 4) {
                result += accumulate(factors.begin(), factors.end(), 0);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums{21, 4, 7};
    Solution solution;
    cout << solution.sumFourDivisors(nums) << endl;
    return 0;
}