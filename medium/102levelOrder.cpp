#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            vector<int> line;
            int len = bfs.size();
            while (len--) {
                TreeNode* node = bfs.front();
                line.push_back(node->val);
                if (node->left != nullptr) bfs.push(node->left);
                if (node->right != nullptr) bfs.push(node->right);
                bfs.pop();
            }
            res.push_back(line);
        }
        return res;
    }
};