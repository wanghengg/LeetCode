//
// Created by wangheng on 2021/4/9.
//

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    vector<vector<int>> result;
    vector<int> path;

    // 先序遍历二叉树得到所有路径
    void dfs(TreeNode* root, int target) {
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root->val);   // 遍历到当前节点，将其值加入path
        target -= root->val;    // 每次target减去当前节点值，如果到达叶子结点时target刚好为0,则满足条件
        if (target == 0 && root->left == nullptr && root->right == nullptr) {
            result.emplace_back(path);
        }
        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return result;
    }
};