//
// Created by wh969 on 2021/6/13.
//

#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int n) {
    return true;
}

class Solution{
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (isBadVersion(mid)) {
                right = mid - 1;    // 与普通二分查找找到相应元素直接返回不同，这里要查第一次满足条件的元素，所以查到之后不能返回，而是继续二分
            } else {
                left = mid + 1;
            }
        }
        return isBadVersion(left) ? left : left + 1;
    }
};

class Solution1{
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};