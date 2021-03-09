#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    /*
     * 对于任意两个节点left，right，其val相等，且left->left->val == right->right->val && left->right->val == right->left->val，
     * 则可以判断两个节点对称
     */
    bool equal(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr || left->val != right->val) return false;
        return equal(left->left, right->right) && equal(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return equal(root->left, root->right);
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    cout << boolalpha << solution.isSymmetric(root) << endl;

    return 0;
}