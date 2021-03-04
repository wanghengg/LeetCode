#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    /*
     * 第一时间想到，奇偶分类用map将奇数放一起，偶数放一起，时间复杂度O(n)
     */
    vector<int> exchange(vector<int>& nums) {
        map<int, vector<int>> data;
        vector<int> result;
        for (auto& iter : nums) {
            if (iter % 2 == 1) {
                data[1].push_back(iter);
            } else {
                data[0].push_back(iter);
            }
        }
        for (auto& iter : data[1]) {
            result.push_back(iter);
        }
        for (auto& iter : data[0]) {
            result.push_back(iter);
        }
        return result;
    }

    /*
     * 首尾指针法，首指针指向第一个数，尾指针指向最后一个数，判断首指针指向的数是否为偶数，尾指针指向的数是否为奇数，如果不是首指针++1，尾指针--1，
     * 当首指针指向偶数，尾指针指向奇数，将两个指针指向的数交换，然后重复之前的操作，知道首尾指针相遇i=j
     */
    vector<int> exchange1(vector<int>& nums) {
        if (nums.empty()) return nums;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < nums.size() && nums[i] % 2 == 1)
                i++;
            while (j >= 0 && nums[j] % 2 == 0)
                j--;
            if (i >= j) break;
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        return nums;
    }

    /*
     * 快慢指针法，定义快慢指针，慢指针寻找下一个奇数应该存放的位置，所以应该从头往后找第一个偶数的位置，快指针不断往后搜索奇数位置，
     * 然后交换快慢指针所指的数，然后继续重复之前的操作，直到快指针到达数组末尾
     */
    vector<int> exchange2(vector<int>& nums) {
        if (nums.empty()) return nums;
        int low = 0, fast = 0;
        while (fast < nums.size()) {
            if(nums[fast] & 1){// 判断nums[fast]是否为奇数
                swap(nums[low], nums[fast]);
                low++;
            }
            fast++;
        }
        return nums;
    }
};

int main() {
    vector<int> nums {1,2,3,4};
    Solution solution;
    vector<int> res = solution.exchange2(nums);
    for (auto& iter : res) {
        cout << iter << endl;
    }
    return 0;
}