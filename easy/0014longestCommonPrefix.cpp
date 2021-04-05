#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        vector<string> subStr = vector<string>(strs.begin() + 1, strs.end());
        string subRes = longestCommonPrefix(subStr);
        string strFir = strs[0];
        int length = min(strFir.size(), subRes.size());
        string result;
        for (int i = 0; i < length; ++i) {
            if (strFir[i] == subRes[i]) {
                result += strFir[i];
            } else {
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs{"dog", "racecar", "car"};
    cout << solution.longestCommonPrefix(strs) << endl;

    return 0;
}