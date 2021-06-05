//
// Created by wangheng on 2021/6/5.
//

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[k]) {
            return false;
        }
        if (k == word.size() - 1) {
            return true;
        }
        board[i][j] = ' '; // 将已经访问过的元素更改为' '，当下次再次访问时与当前word[k]不相等，直接返回false
        bool res = dfs(board, word, i+1, j, k+1) || dfs(board, word, i, j+1, k+1) ||
                dfs(board, word, i-1, j, k+1) || dfs(board, word, i, j-1, k+1);
        board[i][j] = word[k];  // 回溯，恢复已经访问的字符
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};