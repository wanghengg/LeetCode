//
// Created by wangheng on 2020/6/6.
//

#include <iostream>

class Solution{
public:
    int mySqrt(int x) {
        int lo = 0, hi = x;
        int ans = -1;
        // 二分查找
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            // 将mid转换为unsigned long long，然后再和mid相乘，得到的结果也是unsigned long long
            if ((unsigned long long)mid * mid <= x) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::cout << solution.mySqrt(2147395599) << std::endl;

    return 0;
}