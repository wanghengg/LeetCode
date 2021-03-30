#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int getDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return (abs(getDepth(root->left) - getDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
};