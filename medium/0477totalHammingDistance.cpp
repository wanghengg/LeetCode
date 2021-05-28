//
// Created by wangheng on 2021/5/28.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int c = 0;  // 所有元素中第i位为1的元素个数
            for (auto& iter : nums) {
                c += (iter >> i) & 1;
            }
            res += c * (n-c);   // 所有元素的第i位汉明距离为c*(n-c)，c为第i位为1的元素个数，(n-c)为第i位为0的元素个数
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{4, 14, 2};
    cout << solution.totalHammingDistance(nums) << endl;

    return 0;
}