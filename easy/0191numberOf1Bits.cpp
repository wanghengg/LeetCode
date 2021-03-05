//
// Created by wangheng on 2020/5/27.
//

#include <iostream>

class Solution{
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            result += (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::cout << solution.hammingWeight(0b11111111111111111111111111111101) << std::endl;

    return 0;
}