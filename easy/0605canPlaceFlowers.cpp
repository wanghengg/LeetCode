//
// Created by wh969 on 2021/6/14.
//

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < m; ++i) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    count += i / 2;
                } else {
                    count += (i - prev - 2) / 2;
                }
                prev = i;
            }
        }
        if (prev < 0) {
            count += (m + 1) / 2;
        } else {
            count += (m - prev - 1) / 2;
        }
        return count >= n;
    }
};

int main() {
    Solution solution;
    vector<int> flowers{0,0,1,0,1};
    int n = 1;
    cout << solution.canPlaceFlowers(flowers, n) << endl;

    return 0;
}