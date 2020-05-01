//
// Created by wangheng on 2020/5/2.
//

#include <iostream>
using namespace std;

long long Ask(long long u, long long r) {
    long long x, y, ans = 0;
    for (long long i = 1; i <= r / u; i *= 10) {
        x = u * i;
        y = r < (x + i - 1) ? r : (x + i - 1);
        for (long long j = x, k; j <= y; j = k + 1) {
            k = y < (r / (r / j)) ? y : (r / (r / j));
            ans += (k - j + 1) * (r / j);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    long long l, r;
    std::cin >> l >> r;
    for (int i = 1; i <= 9; i++) {
        cout << i << ": " << Ask(i, r) - Ask(i, l-1) << endl;
    }

    return 0;
}