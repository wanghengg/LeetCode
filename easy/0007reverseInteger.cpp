//
// Created by wangheng on 2020/5/27.
//

#include <iostream>
#include <climits>

class Solution{
public:
    int reverse(int x) {
        long long result = 0;
        while (x) {
            result = 10 * result + x % 10;
            x = x / 10;
            if (result < INT_MIN || result > INT_MAX) {
                result = 0;
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::cout << solution.reverse(1299999999) << std::endl;

    return 0;
}