//
// Created by wangheng on 2020/5/27.
//

#include <iostream>
#include <bitset>

class Solution{
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::cout << std::bitset<sizeof(uint32_t)*8>(solution.reverseBits(43261596)) << std::endl;

    return 0;
}