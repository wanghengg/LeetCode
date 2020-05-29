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

// Solution1运行结果正确，但是超时
class Solution1{
public:
    string decodeString(string s) {
        string result;
        string elem;    // inout的每个元素
        int number;
        int count = 0;
        vector<string> inout;
        for (char i : s) {
            if (i != ']') {
                inout.emplace_back(1, i);
                if (i == '[')
                    ++count;
            }
            else {
                string leastString;
                while (count) {
                    while ((elem = inout.back()) != "[") {
                        leastString.append(elem);
                        inout.pop_back();
                    }
                    --count;
                    inout.pop_back();
                    number = stoi(inout.back());
                    inout.pop_back();
                    string temp = leastString;
                    while (--number)
                        leastString.append(temp);
                }
                while (inout.size() > 0) {
                    leastString.append(inout.back());
                    inout.pop_back();
                }
                reverse(leastString.begin(), leastString.end());
                result += leastString;
            }
        }
        for (const string& iter : inout)
            result += iter;
        return result;
    }
};

int main() {
    Solution1 solution;
    std::cout << solution.decodeString("ef3[c5[bg]]9[leetcode]mn") << std::endl;

    return 0;
}