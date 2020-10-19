#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 广度优先搜索按层次遍历树
class Solution{
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<int> res;
        while (!bfs.empty()) {
            TreeNode* front = bfs.front();
            res.push_back(front->val);
            bfs.pop();
            if (front->left) bfs.push(front->left);
            if (front->right) bfs.push(front->right);
        }
        return res;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(9);
    vector<int> res = solution.levelOrder(root);
    for(auto& iter : res) {
        cout << iter << ' ';
    }
    return 0;
}