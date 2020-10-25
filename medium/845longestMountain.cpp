#include <iostream>
#include <vector>
using namespace std;

// 双指针解法
class Solution{
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) return 0;
        int left = 0, right = 0;
        int length = 0;
        bool decrease = false;
        while (right < A.size()-1) {
            while (right < A.size()-1 && A[left] >= A[left+1]) {
                left++;
                right++;
            }
            while (right < A.size()-1 && A[right] < A[right+1]) {
                right++;
            }
            while (right < A.size()-1 && A[right] > A[right+1]) {
                decrease = true;
                right++;
            }
            if (decrease) {
                length = (right - left + 1 > length) ? right - left + 1 : length;
            }
            left = right;
            decrease = false;
        }
        return length;
    }
};

/*
 * 动态规划：用left[i]表示A[i]向左侧最多可以扩展的元素数目，如果A[i-1]<A[i]，那么A[i]可以向左
 * 扩展到A[i-1]，然后继续扩展left[i-1]，因此left[i] = left[i-1]+1，当A[i-1] >= A[i]时，那么
 * A[i]无法继续向右扩展，此时left[i]=0，特别地，当i=0时，left[0]=0，因为最左侧的元素无法向左扩展
 * 向右扩展是一样的方法
 */

class Solution1{
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) return 0;
        int n = A.size();
        vector<int> left(n);
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i-1]) {
                left[i] = left[i-1] + 1;
            } else {
                left[i] = 0;
            }
        }
        vector<int> right(n);
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i+1]) {
                right[i] = right[i+1] + 1;
            } else {
                right[i] = 0;
            }
        }

        int length = 0;
        for (int i = 1; i < n - 1; i++) {
            if (left[i] > 0 && right[i] > 0) {
                length = (left[i] + right[i] + 1 > length) ? left[i] + right[i] + 1 : length;
            }
        }
        return length;
    }
};

int main() {
    vector<int> A{875,884,239,731,723,685};
    Solution1 solution;
    cout << solution.longestMountain(A) << endl;
    return 0;
}