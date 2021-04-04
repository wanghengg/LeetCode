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

/*
 * 第一种解法的时间复杂度是O(kn)
 * 通过一个单调栈可以降低时间复杂度至O(n)，用string模拟单调栈
 */

class Solution1{
public:
    string removeKdigits(string num, int k) {
        string result;
        for (auto& iter : num) {
            while (!result.empty() && result.back() > iter && k) {
                result.pop_back();
                --k;
            }
            if (result.empty() && iter == '0')  // 此时栈为空，且要添加的数字为'0'，即前导0，不应该加入
                continue;
            result.push_back(iter);
        }
        while (k > 0 && !result.empty()) {
            result.pop_back();
            --k;
        }
        return result.empty() ? "0" : result;
    }
};

int main() {
    string num{"123"};
    Solution1 solution;
    cout << solution.removeKdigits(num, 2) << endl;
    return 0;
}