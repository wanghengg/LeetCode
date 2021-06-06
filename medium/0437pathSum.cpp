//
// Created by wangheng on 2021/6/5.
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
    int totalNumber = 0;
    void dfs(TreeNode* root, int target) {
        if (root == nullptr)
            return;
        target -= root->val;
        if (target == 0) {
            totalNumber += 1;   // 不要return，因为之后可能还存在满足路径和等于0的路径，加上之前已有的路径相当于多一条路径
//            return;
        }
        dfs(root->left, target);
        dfs(root->right, target);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        dfs(root, sum);
        pathSum(root->left, sum);   // 左子树递归
        pathSum(root->right, sum);  // 右子树递归
        return totalNumber;
    }
};