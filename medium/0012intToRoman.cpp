//
// Created by wh969 on 2021/6/14.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string intToRoman(int num) {
//        unordered_map<int, string> num2char{{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}};
        string result;
        int tmp = num / 1000;
        if (tmp > 0) {
            while (tmp--) {
                result += "M";
            }
        }
        num = num % 1000;
        tmp = num / 100;
        if (tmp == 9) {
            result += "CM";
        } else if (tmp == 4) {
            result += "CD";
        } else {
            if (tmp >= 5) {
                result += "D";
                tmp -= 5;
            }
            while (tmp--) {
                result += "C";
            }
        }
        num %= 100;
        tmp = num / 10;
        if (tmp == 9) {
            result += "XC";
        } else if (tmp == 4) {
            result += "XL";
        } else {
            if (tmp >= 5) {
                result += "L";
                tmp -= 5;
            }
            while (tmp--) {
                result += "X";
            }
        }
        num %= 10;
        tmp = num / 1;
        if (tmp == 9) {
            result += "IX";
        } else if (tmp == 4) {
            result += "IV";
        } else {
            if (tmp >= 5) {
                result += "V";
                tmp -= 5;
            }
            while (tmp--) {
                result += "I";
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int num = 3994;
    cout << solution.intToRoman(num) << endl;

    return 0;
}