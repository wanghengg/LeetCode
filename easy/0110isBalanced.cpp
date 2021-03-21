#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 自顶向下遍历，可能会重复遍历，时间复杂度为O(n^2)
class Solution{
public:
    int getDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (abs(getDepth(root->left) - getDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        else
            return false;
    }
};

class Solution1{
public:
    /*
     * 自底向上递归类似于后序遍历，对于当前节点，先递归判断其左右子树是否平衡，再判断以当前节点为根的子树是否平衡，
     * 如果一颗子树是平衡的，则返回其高度（高度一定为非负数），否则返回-1。如果存在一个子树不平衡，那么整个二叉树一定不平衡。
     */
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        else {
            return max(leftHeight, rightHeight) + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};