//
// Created by wangheng on 2020/6/4.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 左右列表乘积，用索引左侧所有数字的乘积和右侧所有数字的乘积(即前缀与后缀)相乘得到答案。
 * 初始化两个数组left和right，对于给定索引i，left[i]表示i左侧所有数字的乘积，right[i]
 * 表示i右侧所有数字的乘积，对于数组left和right，left[0]和right[nums.size()-1]应该
 * 为0，因为第一个元素左侧没有元素，所以左侧乘积为1，同理，最后一个元素右侧没有元素，所以
 * 右侧乘积应该为1.
 * left[i] = left[i-1] * nums[i-1]
 * right[i] = right[i+1] * nums[i+1]
 */
class Solution1{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        vector<int> left(size, 1);
        vector<int> right(size, 1);
        for (int i = 1; i < size; ++i) {
            left[i] = left[i-1] * nums[i-1];
            right[size-i-1] = right[size-i] * nums[size-i];
        }
        for (int i = 0; i < size; ++i)
            result[i] = left[i] * right[i];
        return result;
    }
};

/*
 * Solution1中result数组只在计算结果的时候使用，为了节省空间，可以使用result当做left使用，
 * 然后计算出索引i之前的所有元素之和，用一个整数right代替数组right[]，通过迭代的方法计算出
 * 每步i之后的所有元素之积。
 */
class Solution2{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        for(int i = 1; i < size; ++i)
            result[i] = result[i-1] * nums[i-1];
        int right = 1;
        for (int i = size-1; i >= 0; --i) {
            result[i] = result[i] * right;
            right *= nums[i];
        }
        return result;
    }
};

int main() {
    vector<int> nums{1,2,3,4,5};
    Solution2 solution;
    vector<int> result = solution.productExceptSelf(nums);
    for (auto &iter : result)
        cout << iter << ' ';
    return 0;
}