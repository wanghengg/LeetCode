//
// Created by wh969 on 2021/6/11.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i]);
        }
        int len = nums.size();
        for (int i = k; i < len; ++i) {
            if (q.top() < nums[i]) {
                q.pop();
                q.emplace(nums[i]);
            }
        }
        return q.top();
    }
};

/*
 * 改进的快排
 * 快排每次选择一个数作为基准，然后以此基准将数组划分为两个部分，第一个部分里面的数全部小于此基准，
 * 第二部分里面的数全部大于此基准，所以此时基准的位置q已经确定。
 * 经过每次划分操作，一定能确定一个元素的最终位置，即基准的最终位置q，并且保证a[l...q-1]的元素都小于
 * a[q]，a[q+1...r]的元素都大于a[q]，所以只要某次划分的q为倒数第K个下标的时候，我们就已经找到了第K大
 * 的元素。在此过程中，a[l...q-1]和a[q+1...r]是否有序我们不关心，所以可以忽略。
 * 因此我们可以改进快速排序算法，在分解的过程中，对数组进行划分，如果划分得到的q刚好是我们想要的下标，直接返回a[q]，
 * 如果q比目标下标小，我们就递归右边的子区间，否则递归左区间。
 */
class Solution1{
public:
    int quickSelect(vector<int>& nums, int left, int right, int index) {
        int q = randomPartition(nums, left, right);
        if (q == index) {
            return nums[q];
        } else {
            return q < index ? quickSelect(nums, q+1, right, index) : quickSelect(nums, left, q-1, index);
        }
    }

    inline int randomPartition(vector<int>& nums, int left, int right) {
        int index = rand() % (right - left + 1) + left; // 取得[left, right]之间的任意一个随机数
        swap(nums[index], nums[right]); // 将随机选择的nums[index]交换到最右
        return partition(nums, left, right);
    }

    inline int partition(vector<int>& nums, int left, int right) {
        int x = nums[right];    // 此时x是基准
        int index = left - 1;
        for (int j = left; j < right; ++j) {    // 从左往右遍历nums[left...right]，将满足小于基准x的数放在左边
            if (nums[j] <= x) {
                swap(nums[++index], nums[j]);
            }
        }
        swap(nums[index+1], nums[right]);
        return index + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }
};

int main() {
    Solution1 solution;
    vector<int> nums{3,2,1,5,6,4};
    int k = 2;
    cout << solution.findKthLargest(nums, k) << endl;
    return 0;
}