#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
     * 从高位往低位删除数字
     */
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        while (!num.empty() && k--) {
            if (num.size() == 1) {
                num.erase(0, 1);
            } else {
                int index = 1;
                while (index < num.size() && num[index] >= num[index - 1]) {
                    ++index;
                }
                num.erase(index-1, 1);
                while (num[0] == '0') {
                    num.erase(0, 1);
                }
            }
        }
        if (num.empty()) return "0";
        return num;
    }
};

int main() {
    string num{"123"};
    Solution solution;
    cout << solution.removeKdigits(num, 2) << endl;
    return 0;
}