//
// Created by wangheng on 2020/5/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::stoi;
using std::reverse;

class Solution1{
public:
    string decodeString(string s) {
        string result;
        string elem;    // inout的每个元素
        int number;
        vector<string> inout;
        for (char i : s) {
            if (i != ']')
                inout.emplace_back(i, 1);
            else {
                string leastString;
                while ((elem = inout.back()) != "[") {
                    leastString += elem;
                    inout.pop_back();
                }
                inout.pop_back();
                string n = inout.back();
                number = stoi(n);
                inout.pop_back();
                reverse(leastString.begin(), leastString.end());
                for (int j = 0; j < number; ++j)
                    result += leastString;
            }
        }
        return result;
    }
};

int main() {
    Solution1 solution;
    std::cout << solution.decodeString("3[a2[c]]") << std::endl;

    return 0;
}