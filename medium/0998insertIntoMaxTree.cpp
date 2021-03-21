#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    // 递归，题目要求新插入的节点在右子树
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (val > root->val) {
            TreeNode* tree = new TreeNode(val);
            tree->left = root;
            return tree;
        }
        TreeNode* right = insertIntoMaxTree(root->right, val);
        root->right = right;
        return root;
    }
};