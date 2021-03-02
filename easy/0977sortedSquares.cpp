#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        for (int i = 0; i < A.size(); i++) {
            res[i] = A[i] * A[i];
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<int> A{-4, -1, 0, 3, 10};
    Solution solution;
    vector<int> res = solution.sortedSquares(A);
    for (auto& it : res) {
        cout << it << ' ';
    }
    return 0;
}