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
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return isBadVersion(left) ? left : left + 1;
    }
};