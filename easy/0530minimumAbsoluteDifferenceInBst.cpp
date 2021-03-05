#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 因为二叉搜索树中序遍历是有序的，所以任意两个元素之差绝对值最小一定是两个相邻的元素，所以可以遍历整个二叉搜索树
// 下面使用递归实现中序遍历
class Solution{
private:
    int result = INT_MAX;
    TreeNode* pre;
public:
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (pre != nullptr) {
            result = min(result, root->val - pre->val);
        }
        pre = root; // 记录前一个
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return result;
    }
};

class Solution1{
public:
    int getMinimumDifference(TreeNode* root) {

    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    cout << solution.getMinimumDifference(root) << endl;
    return 0;
}