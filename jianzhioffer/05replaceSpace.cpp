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
};

int main() {
    Solution solution;
    string s = "We are happy.";
    cout << solution.replaceSpace(s) << endl;

    return 0;
}