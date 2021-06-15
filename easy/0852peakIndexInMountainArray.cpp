//
// Created by wh969 on 2021/6/15.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            } else if (arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

class Solution1{
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;   // 根据题意arr[0]不可能是山峰
        int right = arr.size() - 2;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid+1]) {    // 寻找最小的满足arr[i]>arr[i+1]的下标i
                right = mid-1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution1 solution;
    vector<int> arr{3,5,3,2,0};
    cout << solution.peakIndexInMountainArray(arr) << endl;
    return 0;
}