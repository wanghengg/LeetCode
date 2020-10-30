#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int removeElement(vector<int>& nums, int val) {
        // remove没有删除等于val的值，只是将没有匹配的元素放在前面，返回一个指向新的尾后迭代器
        // 即[3,2,2,3]，如果val=3，那么新的排序为[2,2,3,3]，真正的删除操作应该使用erase
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

// 快慢指针法，两个指针i和j，i是慢指针，j是快指针，i和j同时从0开始，当nums[j]=val时，递增j跳过改元素，
// nums[j] != val时，将nums[j]拷贝到i位置，然后同时递增i、j，直到j到达末尾
class Solution1{
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;   // i慢指针，j快指针
        for(; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
    Solution1 solution;
    vector<int> nums{3,2,2,3};
    int val = 3;
    cout << solution.removeElement(nums, val) << endl;

    return 0;
}