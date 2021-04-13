//
// Created by wangheng on 2021/4/13.
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
    int minDiffBST(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> mark;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.emplace(root);
                root = root->left;
            }
            auto top = stack.top();
            mark.emplace_back(top->val);
            stack.pop();
            root = top->right;
        }
        if (mark.size() < 2) return 0;
        int result = INT_MAX;
        for (int i = 1; i < mark.size(); ++i) {
            result = min(result, mark[i] - mark[i-1]);
        }
        return result;
    }
};