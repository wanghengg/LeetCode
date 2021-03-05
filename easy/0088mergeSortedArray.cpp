//
// Created by wangheng on 2020/6/1.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(m+n);
        int i, j, k = 0;
        for (i = 0, j = 0; i < m && j < n;) {
            result[k++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
        }
        for (; i < m; i) {
            result[k++] = nums1[i++];
        }
        for (; j < n; j) {
            result[k++] = nums2[j++];
        }
        nums1 = result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    solution.merge(nums1, 3, nums2, 3);
    for (auto& iter : nums1)
        cout << iter << ' ';
    return 0;
}