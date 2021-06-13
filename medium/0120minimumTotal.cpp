//
// Created by wangheng on 2021/6/10.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
//        int n = triangle.end()->size();
        int result = triangle[0][0];
        int curPosition = 0;
        for (int i = 1; i < m; ++i) {
            if (triangle[i][curPosition] < triangle[i][curPosition+1]) {
                result += triangle[i][curPosition];
            } else {
                result += triangle[i][curPosition+1];
                curPosition += 1;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> triangle{{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    Solution solution;
    cout << solution.minimumTotal(triangle) << endl;
    return 0;
}