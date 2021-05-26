//
// Created by wangheng on 2021/4/25.
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* cur = dummy;
        stack<TreeNode*> stack;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {   // 沿最左边一直入栈
                stack.emplace(root);
                root = root->left;
            }
            auto top = stack.top();
            top->left = nullptr;    // 使左子树为null
            cur->right = top;
            cur = cur->right;
            root = top->right;
            stack.pop();
        }
        return dummy->right;
    }
};