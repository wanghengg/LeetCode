#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<int> level;
        queue<TreeNode*> nextLevel;
        while (!bfs.empty()) {
            while (!bfs.empty()) {
                TreeNode *front = bfs.front();
                level.push_back(front->val);
                bfs.pop();
                if (front->left) nextLevel.push(front->left);
                if (front->right) nextLevel.push(front->right);
            }
            res.push_back(level);
            level = {};
            bfs = nextLevel;
            nextLevel = {};
        }
        return res;
    }

    // 获取当层节点数
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int len = bfs.size();
            vector<int> level;
            while (len--) {
                TreeNode* front = bfs.front();
                bfs.pop();
                level.push_back(front->val);
                if (front->left) bfs.push(front->left);
                if (front->right) bfs.push(front->right);
            }
            res.push_back(level);
        }
        return res;
    }
};