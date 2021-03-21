#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int count = q.size();
            ++depth;
            while (count--) {
                TreeNode* tmp = q.front();
                q.pop();

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }

        return depth;
    }

    // 树的最大深度等于其左右子树最大深度加1
    int maxDepth1(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth1(root->left), maxDepth1(root->right)) + 1;
    }
};