#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string replaceSpace(string s) {
        string result;
        for (auto& iter : s) {
            if (iter == ' ') {
                result += "%20";
            } else {
                result += iter;
            }
        }
        return result;
    }

    // 原地替换
    string replaceSpace(string s) {
        // 先计算字符串中空格的个数
        int count = 0;
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            if (s[i] == ' ') {
                ++count;
            }
        }
        s.resize(length + count * 2);
        for (int i = length - 1, j = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else {
                s[j--] = s[i];
            }
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s = "We are happy.";
    cout << solution.replaceSpace(s) << endl;

    return 0;
}