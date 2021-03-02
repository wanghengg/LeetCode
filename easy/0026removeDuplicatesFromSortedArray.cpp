#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i = 1;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[j-1]) {
            nums[i++] = nums[j];
        }
    }
    return i;
}

int main() {
    vector<int> nums = {};
    cout << removeDuplicates(nums) << endl;

    return 0;
}