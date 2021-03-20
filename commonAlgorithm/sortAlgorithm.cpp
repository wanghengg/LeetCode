#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SortAlgorithm{
public:
    // 计数排序，时间复杂度O(n)，稳定
    void countSort(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> count(maxNum + 1, 0);
        for (auto& iter : nums) {
            count[iter]++;
        }
        int index = 0;
        for (int i = 0; i < count.size(); i++) {
            while (count[i]--) {
                nums[index++] = i;
            }
        }
    }

    // 桶排序
    void bucketSort(vector<int>& nums) {

    }

    // 基数排序
    void radixSort(vector<int>& nums) {}

    // 冒泡排序，时间复杂度O(n^2)，稳定
    void bubbleSort(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length - 1; ++i) {
            for (int j = 0; j < length - i - 1; ++j) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }

    // 快速排序，时间复杂度O(nlogn)，不稳定
    void quickSort(vector<int>& nums, int start, int end) {
        // 如果区间只有一个元素，递归结束
        if (start >= end) return;
        int tmp = nums[start];    // 将区间的第一个数当做基准
        int left = start;          // 指向最左位置
        int right = end;            // 指向最右位置
        while (left < right) {
            // 当右边的数大于基准数时，略过，继续向左查找
            // 不满足条件时跳出循环，此时的j对应的元素是小于基准元素的
            while (left < right && nums[right] >= tmp)
                right--;
            // 将右边小于等于基准元素的数填入左边相应位置
            nums[left] = nums[right];
            // 当左边的数小于等于基准数时，略过，继续向右查找
            // 不满足条件时跳出循环，此时的i对应的元素是大于等于基准元素的
            while (left < right && nums[left] <= tmp)
                left++;
            // 将左边大于基准元素的数填入右边相应位置
            nums[right] = nums[left];
        }
        // 将基准元素填入相应位置
        nums[left] = tmp;
        // 此时的i即为基准元素的位置
        // 对基准元素的左边子区间进行相似的快速排序
        quickSort(nums, start, left - 1);
        //对基准元素的右边子区间进行相似的快速排序
        quickSort(nums, left + 1, end);
    }

    // 插入排序，时间复杂度O(n^2)，稳定
    void insertSort(vector<int>& nums) {
        int length = nums.size();
        for (int i = 1; i < length; ++i) {
            int tmp = nums[i];
            int j;
            for (j = i - 1; j >= 0 && tmp < nums[j]; --j) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }

    // 希尔排序
    void shellSort(vector<int>& nums) {}

    // 选择排序，时间复杂度O(n)，不稳定
    void selectSort(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length - 1; ++i) {
            int min = i;    // 保存最小元素的索引
            for (int j = i + 1; j < length; ++j) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            swap(nums[i], nums[min]);
        }
    }

    // 堆排序
    void heapSort(vector<int>& nums) {}

    // 归并排序
    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> res;
        int ia = 0, ib = 0;
        while (ia < a.size() && ib < b.size()) {
            if (a[ia] < b[ib]) {
                res.push_back(a[ia++]);
            } else {
                res.push_back(b[ib++]);
            }
        }
        if (ia == a.size()) {
            while (ib < b.size()) {
                res.push_back(b[ib++]);
            }
        }
        if (ib == b.size()) {
            while (ia < a.size()) {
                res.push_back(a[ia++]);
            }
        }
        return res;
    }
    vector<int> mergeSort(vector<int> nums) {
        int length = nums.size();
        if (length < 2) return nums;
        int mid = length / 2;
        vector<int> front(nums.begin(), nums.begin() + mid);
        vector<int> back(nums.begin() + mid, nums.end());
        return merge(mergeSort(front), mergeSort(back));
    }
};


int main() {
    SortAlgorithm sortAlgorithm;
    vector<int> nums = {2,8,2,1,9,3,7};
    vector<int> result = sortAlgorithm.mergeSort(nums);
    for (auto& iter : result) {
        cout << iter << ' ';
    }

    return 0;
}