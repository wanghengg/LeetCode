#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numbers;
        unordered_set<int> result;
        for(auto& it : nums1) {
            numbers.insert(it);
        }
        for(auto& it : nums2) {
            if (numbers.count(it)) {
                result.insert(it);
            }
        }
        vector<int> res;
        res.reserve(result.size());
        for(auto& iter : result) {
            res.push_back(iter);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};
    vector<int> result = solution.intersection(nums1, nums2);
    for(auto& it : result) {
        cout << it << ' ';
    }

    return 0;
}