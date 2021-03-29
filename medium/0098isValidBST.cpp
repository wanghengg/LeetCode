#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* rihgt) : val(x), left(left), right(right) {}
};

class Solution{
public:
    /*
     * 设计一个递归函数helper(root, lower, upper)判断以root为根的子树节点的值是否都在(l,r)内
     * 如果root的值不在(l,r)的范围内，说明不满足条件直接返回。否则我们要判断其左右子树是否满足，那么
     * 其左子树的范围应该是(l, root->val)，其右子树的范围应该是(root->val, r)
     */
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        // 递归调用的入口应该是lower = LONG_LONG_MIN, upper=LONG_LONG_MAX，表示初始时根节点的值可以任意值
        return helper(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};

class Solution1{
    // 因为二叉搜索树的中序遍历应该是有序的，所以可以通过判断中序遍历是否有序来判断是不是二叉搜索树
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long )INT_MIN - 1;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (root->val <= inorder) {
                return false;
            }
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};