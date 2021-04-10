#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // 很显然，可以用递归，从后往前看
    int translateNum(int num) {
        if (num <= 9) return 1; // 当num小于等于9，只可能有一种翻译方式
        // 当num的最后两位数大于等于10且小于等于25时可能有两种翻译方式，（1）直接把最后两位当做一个字母，（2）把最后两位当做两个字母
        if (num % 100 <= 25 && num % 100 >= 10) return translateNum(num / 100) + translateNum(num / 10);
        else return translateNum(num / 10); // 只能把最后一位当做一个字母翻译
    }
};