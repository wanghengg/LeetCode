#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution{
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewel;
        for (auto& it : J) {
            jewel.insert(it);
        }
        int res = 0;
        for (auto& it : S) {
            if (jewel.count(it)) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    string J = "aA", S = "aAAbbbb";
    Solution solution;
    cout << solution.numJewelsInStones(J, S) << endl;
    return 0;
}