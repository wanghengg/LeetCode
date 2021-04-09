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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {  // 当前节点为nullptr，直接返回false
            return false;
        }
        targetSum -= root->val; // 每次将targetSum减去当前节点值
        if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
            return true;    // targetSum刚好为0且当前节点为叶子结点时返回true
        }
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum); // 递归
    }
};