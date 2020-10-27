#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            vector<int> line;
            int length = bfs.size();    // bfs中只保留一行的数据，当前行的节点个数
            while (length--) {  // 将当前行的节点全部从bfs中弹出
                TreeNode* front = bfs.front();
                line.push_back(front->val);
                if (front->left != nullptr) bfs.push(front->left);
                if (front->right != nullptr) bfs.push(front->right);
                bfs.pop();
            }
            res.push_back(line);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};