#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 递归方法计算前序遍历
class Solution{
public:
    void preorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

// 迭代方法
/*
 * 递归的时候隐式地维护了一个栈，迭代方法就是把栈显示地模拟出来
 */
class Solution1{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }
};

class Solution2{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        stk.emplace(node);
        while (!stk.empty()) {
            node = stk.top();
            res.push_back(node->val);
            stk.pop();
            if (node->right != nullptr) stk.emplace(node->right);
            if (node->left != nullptr) stk.emplace(node->left);
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    Solution2 solution;
    vector<int> res = solution.preorderTraversal(root);
    for(auto& it : res) {
        cout << it << ' ';
    }
    return 0;
}