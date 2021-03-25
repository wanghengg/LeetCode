#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void reverStr(string& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
    string reverseWords(string s) {
        stringstream instring(s);
        vector<string> words;
        string word;
        while (instring >> word) {
            words.push_back(word);
        }
        string res;
        for (auto& iter : words) {
            res += iter;
            res += ' ';
        }
        res = res.substr(0, res.size() - 1);
        int length = res.size();
        int left = 0, right = length - 1;
        reverStr(res, left, right);
        int first = 0, second = 0;
        while (first < length) {
            while (second < length && res[second] != ' ') {
                ++second;
            }
            reverStr(res, first, second - 1);
            ++second;
            first = second;
        }
        return res;
//        int length = s.size();
//        int left;
//        for (left = 0; left < length; ++left) {
//            if (s[left] != ' ')
//                break;
//        }
//        int right;
//        for (right = length - 1; right >= 0; --right) {
//            if (s[right] != ' ')
//                break;
//        }
//        s = s.substr(left, right - left + 1);

    }
};

int main() {
    Solution solution;
    string  s{"   the sky is blue    "};
    cout << solution.reverseWords(s) << endl;

    return 0;
}