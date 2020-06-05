//
// Created by wangheng on 2020/6/5.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1{
private:
    static int directions[4][2];
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int total = rows * columns;
        vector<int> result(total);

        int row = 0, column = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; ++i) {
            result[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn])
                directionIndex = (directionIndex + 1) % 4;
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return result;
    }
};

int Solution1::directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};


// 按层模拟
class Solution2{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> result;

        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;

        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; ++column)
                result.push_back(matrix[top][column]);
            for (int row = top + 1; row <= bottom; ++row)
                result.push_back(matrix[row][right]);
            // 如果当前层只有一行或者只有，那么不需要下面的循环，否则会重复
            if (left < right && top < bottom) {
                for (int column = right - 1; column >= left; --column)
                    result.push_back(matrix[bottom][column]);
                for (int row = bottom - 1; row > top; --row)
                    result.push_back(matrix[row][left]);
            }
            ++left;
            ++top;
            --right;
            --bottom;
        }
        return result;
    }
};

int main() {
    Solution2 solution;
    vector<vector<int>> matrix{{7}, {9}, {6}};
    vector<int> result = solution.spiralOrder(matrix);
    for (auto &iter : result)
        cout << iter << ' ';

    return 0;
}