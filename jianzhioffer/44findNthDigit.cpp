//
// Created by wh969 on 2021/4/9.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findNthDigit(int n) {
        if (n == 0) return 0;
        int k = 1;
        // k位数所占位数总和为 9*k*10^(k-1)位
        // 下面计算第n位是几位数
        while (n - 9 * k * pow(10, k - 1) > 0) {
            n -= 9 * k * pow(10, k - 1);
            ++k;
        }
        int start = n / k;  // 第start个k位数
        int offset = n % k; // 相对于第start个k位数的偏移，即第start+1个K位数的从高到低第offset位
        int target = pow(10, k - 1) + start - 1;    // 计算第start个k位数的实际值
        if (offset == 0) return target % 10;    // 如果offset为0，则刚好为target的最低位
        target += 1;    // 若offset不为0，则需将target+1，表示第start+1个k位数
        return int(target / pow(10, k - offset)) % 10;  // k位数从高位开始第offset位计算
    }
};

int main() {
    Solution solution;
    cout << solution.findNthDigit(3) << endl;
    return 0;
}