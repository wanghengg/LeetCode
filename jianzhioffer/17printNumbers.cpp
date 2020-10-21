#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> printNumbers(int n) {
        int maxNumber = 0;
        while (n--) {
            maxNumber = maxNumber * 10 + 9;
        }
        vector<int> res(maxNumber, 0);
        for(int i = 0; i < maxNumber; i++) {
            res[i] = i + 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n = 2;
    vector<int> res = solution.printNumbers(n);
    for (auto iter : res) {
        cout << iter << ' ';
    }
    return 0;
}