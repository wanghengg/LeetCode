//
// Created by wangheng on 2021/9/3.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0) return {};
        priority_queue<int> q;
        int i = 0;
        int n = arr.size();
        for(; i < k; ++i) {
            q.push(arr[i]);
        }
        for(; i < n; ++i) {
            if(arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        vector<int> res;
        while(!q.empty()) {
            res.emplace_back(q.top());
            q.pop();
        }
        return res;
    }
};

class Solution1 {
public:
    void randomized_selected(vector<int>& nums, int left, int right, int k) {
        if (left >= right) return;
        int pos = rand() % (right - left + 1) + left;
        int pivot = nums[pos];
        swap(nums[pos], nums[right]);
        int index = left;
        for(int i = left; i < right; ++i) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[index++]);
            }
        }
        swap(nums[index], nums[right]);
        if (k == index) return;
        if (k < index) {
            randomized_selected(nums, left, index-1, k);
        } else {
            randomized_selected(nums, index+1, right, k);
        }
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        randomized_selected(arr, 0, arr.size()-1, k);
        vector<int> res(k);
        for(int i = 0; i < k; ++i) {
            res[i] = arr[i];
        }
        return res;
    }
};

int main() {
    Solution1 solution1;
    vector<int> arr{1,3,5,7,2,4,6,8};
    int k = 4;
    vector<int> res = solution1.smallestK(arr, k);
    for(auto& iter : res) {
        cout << iter << " ";
    }
    return 0;
}