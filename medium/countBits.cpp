//
// Created by wangheng on 2020/5/27.
//

#include <iostream>
#include <vector>
using namespace std;

// 暴力解法
//int popCount(int x) {
//    int count = 0;
//    while (x > 0) {
//        ++count;
//        x &= (x - 1);
//    }
//    return count;
//}
//
//vector<int> countBits(int num) {
//    vector<int> result;
//    for (int i = 0; i <= num; ++i)
//        result.push_back(popCount(i));
//    return result;
//}

/*
 * i&(i-1)可以去掉i最右边的一个1(如果有的话)，因为i&(i-1)比i小，在前面已经计算出来，所以i
 * 的1的位数就是i&(i-1)的1的位数加1，时间复杂度为O(n)，空间复杂度为O(n)
 */
vector<int> countBits(int num) {
    vector<int> result = {0};
    for (int i = 1; i <= num; ++i)
        result.push_back(result[i & (i - 1)] + 1);
    return result;
}

int main() {
    for (auto iter : countBits(2))
        std::cout << iter << ' ';
    return 0;
}