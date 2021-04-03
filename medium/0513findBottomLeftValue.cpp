#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 使用广度优先搜索
class Solution{
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res;
        while (!q.empty()) {
            res = q.front()->val;
            int len = q.size();
            while (len--) {
                TreeNode* front = q.front();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
                q.pop();
            }
        }
        return res;
    }
};

// 使用深度优先搜索
class Solution1{
public:
    int maxHeight = 0;
    int height = 0;
    int res;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        ++height;
        if (height > maxHeight) {
            maxHeight = height;
            res = root->val;
        }
        dfs(root->left);
        dfs(root->right);
        --height;   // 这里相当于回溯，height要减1
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root);
        return res;
    }
};