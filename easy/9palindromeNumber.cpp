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

int main() {
    Solution solution;
    cout << boolalpha << solution.isPalindrome(2147483647) << endl;

    return 0;
}