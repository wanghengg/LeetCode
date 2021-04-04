#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
     * 用map记录(兔子的答案，相同答案的个数)
     * 说有k个兔子颜色和我一样的兔子最多有k+1，剩余的兔子应该有其他的颜色
     */
    int numRabbits(vector<int>& answers) {
        map<int, int> numbers;
        for (auto& iter : answers) {
            numbers[iter]++;
        }
        int result = 0;
        for (auto& iter : numbers) {
            while (iter.second > (iter.first + 1)) {
                result += (iter.first + 1);
                iter.second -= (iter.first + 1);
            }
            result += (iter.first + 1);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> answers{0,0,1,1,1};
    cout << solution.numRabbits(answers) << endl;
    return 0;
}