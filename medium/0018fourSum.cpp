#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());     // 先对数组排序，后面可以用双指针
        int length = (int)nums.size();

        for (int i = 0; i < length - 3; i++) {  // 第一层循环，i从0开始
            if (i > 0 && nums[i] == nums[i-1]) {    // 如果重复则跳过，例如[2,2,2,...]，只需要取一次2
                continue;
            }
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {     // 最小的和大于target，直接跳出循环
                break;
            }
            if (nums[i] + nums[length-1] + nums[length-2] + nums[length-1] < target) {  // 当前最大和小于target，增加i
                continue;
            }

            for (int j = i + 1; j < length - 2; j++) {      // 第二层循环，j从i+1开始
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums[length-2] + nums[length-1] < target) {
                    continue;
                }
                int left = j + 1;   // 左指针
                int right = length - 1;     // 右指针
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum < target) {
                        while (left < right && nums[left+1] == nums[left]) {    // 保证不重复
                            left++;
                        }
                        left++;
                    }
                    else if (sum == target) {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left+1] == nums[left]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right-1]) {
                            right--;
                        }
                        right--;
                    } else {
                        while (left < right && nums[right] == nums[right-1]) {
                            right--;
                        }
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, -1, -1, -2, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);
    for (auto& item : result) {
        for (auto& iter : item) {
            cout << iter << ' ';
        }
        cout << endl;
    }

    return 0;
}