//
// Created by wh969 on 2021/5/27.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    void backtrack(vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        int n = board.size();
        for (int col = 0; col < n; ++col) {
            if (!isValid(board, row, col))  // 判断此点是否合法
                continue;
            board[row][col] = 'Q';  // 选择此点放置Queen
            backtrack(board, row + 1);  // 继续探索第row+1行
            board[row][col] = '.';  // 撤销选择
        }
    }

    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列中是否有皇后互相冲突
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // 检查右上方是否存在皇后相互冲突，由于皇后按行放置所以不用检测同一行、左下方和右下方这三种情况
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // 检查左上方是否存在皇后相互冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n = 4;
    Solution solution;
    vector<vector<string>> res = solution.solveNQueens(n);
    for (auto& iter : res) {
        for (auto& item : iter) {
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}