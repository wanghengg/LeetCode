#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    bool isLongPressedName(string name, string typed) {
        if (name.empty()) return true;
        int i = 0, j = 0;
        while (i < name.size()) {
            int count = 1;  // count用于计算name中连续重复的字符个数
            while (i+1 < name.size() && name[i+1] == name[i]) {
                i++;
                count++;
            }
            char cur = name[i];
            i++;
            // type中至少有count个cur
            while (count--) {
                if (typed[j] == cur) {
                    j++;
                } else {
                    return false;
                }
            }
            // 如果还有多余的cur，则计数j增加
            while (typed[j] == cur) {
                j++;
            }
        }
        if (j == typed.size()) return true;     // 最终j到达typed末尾返回true
        return false;   // 如果计数j没有到达末尾，说明typed中有多余的不同于name中最后一个字符的字符，即打字错误不匹配而不是长按出现重复字符，返回false
    }
};

int main() {
    Solution solution;
    string name = "l", typed = "lleeelee";
    cout << boolalpha << solution.isLongPressedName(name, typed) << endl;
    return 0;
}