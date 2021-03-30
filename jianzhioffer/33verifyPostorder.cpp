#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool verify(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;
        int root = postorder[right];
        int index = right-1;
        while (index >= 0 && postorder[index] > root) {
            --index;
        }
        int mid = index;
        while (index >= 0) {
            if (postorder[index] > root) {
                return false;
            } else {
                --index;
            }
        }
        return verify(postorder, left, mid) && verify(postorder, mid + 1, right - 1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size()-1);
    }
};

int main() {
    vector<int> postorder{5,4,3,2,1};
    Solution solution;
    cout << solution.verifyPostorder(postorder) << endl;

    return 0;
}