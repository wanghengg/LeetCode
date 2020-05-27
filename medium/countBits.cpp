//
// Created by wangheng on 2020/5/27.
//

#include <iostream>
#include <vector>
using namespace std;

// 暴力解法
int popCount(int x) {
    int count = 0;
    while (x > 0) {
        ++count;
        x &= (x - 1);
    }
    return count;
}

vector<int> countBits(int num) {
    vector<int> result;
    for (int i = 0; i <= num; ++i)
        result.push_back(popCount(i));
    return result;
}

int main() {
    for (auto iter : countBits(2))
        std::cout << iter << ' ';
    return 0;
}