#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 暴力解法，先按逆中序遍历，然后返回逆中序遍历的第k个元素
class Solution{
public:
    vector<int> result;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->right);
        result.push_back(root->val);
        inorder(root->left);
    }
    int kthLargest(TreeNode* root, int k) {
        inorder(root);
        return result[k-1];
    }
};

// 提前停止遍历，每次遍历一个节点，k减1，当k为0时，停止遍历
class Solution1{
public:
    void inorder(TreeNode* root, int& result, int& k) {
        if (root == nullptr) return;
        inorder(root->right, result, k);
        if (--k == 0) {
            result = root->val;
            return;
        }
        if (k < 0)
            return;
        else
            inorder(root->left, result, k);
    }
    int kthLargest(TreeNode* root, int k) {
        int result;
        inorder(root, result, k);
        return result;
    }
};

int main() {
    Solution1 solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << solution.kthLargest(root, 1);
    return 0;
}