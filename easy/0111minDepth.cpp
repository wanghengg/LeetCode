//
// Created by wangheng on 2021/4/11.
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int depth = 1;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; ++i) {
                auto front = q.front();
                if (front->left == nullptr && front->right == nullptr) return depth;
                if (front->left) q.emplace(front->left);
                if (front->right) q.emplace(front->right);
                q.pop();
            }
            ++depth;
        }
        return depth;
    }
};