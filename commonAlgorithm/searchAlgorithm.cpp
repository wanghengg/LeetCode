#include <iostream>
#include <vector>
using namespace std;

class SearchAlgorithm{
public:
    // 有效区间取[left, right]，即左闭右闭区间
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};

int main() {
    SearchAlgorithm solution;
    vector<int> nums{1,3,5,6,10,14,19,26};
    int target = 26;
    cout << solution.binarySearch(nums, target) << endl;
    return 0;
}