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
    void flatten(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* cur = new TreeNode(0);
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.emplace(root->right); // 因为后面root的右子节点会更改，所以先把右子树的根节点保存下来
                cur->right = root;
                cur->left = nullptr;
                cur = cur->right;
                root = root->left;
            }
            root = stack.top();
            stack.pop();
        }
    }
};