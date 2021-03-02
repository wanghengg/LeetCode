//
// Created by wangheng on 2020/6/1.
//

#include <iostream>

class Solution{
public:
    int uniquePaths(int m, int n) {
        int result[m][n];
        result[0][0] = 1;
        for (int i = 1; i < m; ++i)
            result[i][0] = 1;
        for (int j = 1; j < n; ++j)
            result[0][j] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                result[i][j] = result[i][j-1] + result[i-1][j];
        }
        return result[m-1][n-1];
    }
};

int main() {
    Solution solution;
    std::cout << solution.uniquePaths(1,0) << std::endl;
    return 0;
}