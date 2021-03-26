//
// Created by wangheng on 2020/5/31.
//

#include <iostream>
using namespace std;

class Solution{
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long origin = x;
        long result = 0;
        while (0 < x) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result == origin;
    }
};

// 只反转一半的数字
class Solution1{
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reverseNumber = 0;
        while (x > reverseNumber) {
            reverseNumber = reverseNumber * 10 + x % 10;
            x = x / 10;
        }
        return x == reverseNumber || x == reverseNumber / 10;
    }
};

int main() {
    Solution solution;
    cout << boolalpha << solution.isPalindrome(2147483647) << endl;

    return 0;
}