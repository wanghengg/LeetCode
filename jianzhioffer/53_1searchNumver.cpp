#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target) {
        return count(nums.begin(), nums.end(), target);
    }
};

int main() {
    Solution solution;
    vector<int> nums{5,7,7,8,8,10};
    int target = 8;
    cout << solution.search(nums, target) << endl;

    return 0;
}