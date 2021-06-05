//
// Created by wangheng on 2021/6/6.
//

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

class Solution{
public:
    vector<vector<int>> result;
    void dfs(TreeNode* root, vector<int> path) {
        if (root == nullptr) return;
        path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            result.emplace_back(path);
            return;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        vector<string> treePaths;
        for (auto& iter : result) {
            string str(to_string(iter[0]));
            for(int i = 1; i < iter.size(); ++i) {
                str += "->";
                str += to_string(iter[i]);
            }
            treePaths.emplace_back(str);
        }
        return treePaths;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    vector<string> result = solution.binaryTreePaths(root);
    for (auto& iter : result) {
        cout << iter << endl;
    }
    return 0;
}