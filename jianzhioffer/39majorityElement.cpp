#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mark;
        int i;
        for (i = 0; i < nums.size(); ++i) {
            mark[nums[i]]++;
            if (mark[nums[i]] > nums.size() / 2) {
                break;
            }
        }
        return nums[i];
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << solution.majorityElement(nums) << endl;

    return 0;
}