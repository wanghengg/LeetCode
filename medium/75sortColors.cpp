#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3, 0);
        for (auto& iter : nums) {
            colors[iter]++;
        }
        int index = 0;
        for (int i = 0; i < colors.size(); i++) {
            while (colors[i] > 0) {
                nums[index++] = i;
                colors[i]--;
            }
        }
    }
};

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    Solution solution;
    solution.sortColors(nums);
    for (auto& iter : nums) {
        cout << iter << ' ';
    }

    return 0;
}