#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SortAlgorithm{
public:
    // 计数排序
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
    void bucketSort(vector<int>& nums) {}

    // 基数排序
    void radixSort(vector<int>& nums) {}

    // 冒泡排序
    void bubbleSort(vector<int>& nums) {}

    // 归并排序
    void mergeSort(vector<int>& nums) {}

    // 插入排序
    void insertSort(vector<int>& nums) {}

    // 快速排序
    void quickSort(vector<int>& nums) {}

    // 选择排序
    void selectSort(vector<int>& nums) {}

    // 堆排序
    void heapSort(vector<int>& nums) {}

    // 希尔排序
    void shellSort(vector<int>& nums) {}
};


int main() {
    SortAlgorithm sortAlgorithm;
    vector<int> nums = {2,8,2,1,9,3,7};
    sortAlgorithm.countSort(nums);
    for (auto& iter : nums) {
        cout << iter << ' ';
    }

    return 0;
}