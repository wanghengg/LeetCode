//
// Created by wangheng on 2021/6/5.
//

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    void dfs(vector<TreeNode*> path, TreeNode* root, TreeNode* target, vector<TreeNode*> target_path) {
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root);
        if (root == target) {
            target_path = path;
            return;
        }
        dfs(path, root->left, target, target_path);
        dfs(path, root->right, target, target_path);
        path.pop_back();
    }
    // 获得从根节点到目标节点的路径
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> path;
        vector<TreeNode*> target_path;
        dfs(path, root, target, target_path);
        return target_path;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root, p);
        vector<TreeNode*> path_q = getPath(root, q);
        int i;
        for (i = 0; i < path_p.size() && i < path_q.size(); ++i) {
            if (path_p[i] != path_q[i]) {
                break;
            }
        }
        return path_p[i-1];
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    Solution solution;
    TreeNode* res = solution.lowestCommonAncestor(root, root, root->left);
    cout << res->val << endl;
    return 0;
}