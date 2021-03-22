#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int a[2] = {-1, -1};
        for (auto& iter : s) {
            int num = iter - '0';
            if (num >= 0 && num <= 9) {
                if (num > a[0]) {
                    a[1] = a[0];
                    a[0] = num;
                } else if (num != a[0] && num > a[1]) { // 保证不会有相同最大值保存进来
                    a[1] = num;
                }
            }
        }
        return a[1];
    }
};

int main() {
    string s{"dfkadfj889932"};
    Solution solution;
    cout << solution.secondHighest(s) << endl;
    return 0;
}