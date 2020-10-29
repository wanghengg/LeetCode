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
    int dfs(TreeNode* root, int preSum) {
        if (root == nullptr) {  // 如果root为空指针，直接返回0
            return 0;
        }
        int sum = preSum * 10 + root->val;  // 当前和等于上一个和乘10然后加上当前值
        if (root->left == nullptr && root->right == nullptr) {  // 到达叶节点
            return sum;     // 返回结果
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);    // 未到达叶节点，和等于当前和与左右子节点相加然后将得到的两个值求和
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << solution.sumNumbers(root);
    return 0;
}