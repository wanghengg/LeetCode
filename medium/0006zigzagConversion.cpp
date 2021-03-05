//
// Created by wangheng on 2020/6/2.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int len = s.size();
        vector<string> res(numRows,"");
        int number = 2 * numRows - 2;
        for (int i = 0; i < len; ++i) {
            int index = i % number;
            if (index < numRows)
                res[index].push_back(s[i]);
            else {
                res[number-index].push_back(s[i]);
            }
        }
        s = "";
        for (auto &iter : res)
            s += iter;
        return s;
    }
};

int main() {
    Solution solution;
    string s{"LEETCODEISHIRING"};
    int numRows = 1;
    cout << solution.convert(s, numRows) << endl;
    return 0;
}