//
// Created by wangheng on 2021/6/4.
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
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> path;
        while (root != target) {
            path.emplace_back(root);
            if (root->val > target->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        path.emplace_back(root);
        return path;
    }
    // 题目给出的树是二叉查找树，给出查找p和q的路径，然后比较两者的路径找到最后一个相同的节点就是最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root, p);
        vector<TreeNode*> path_q = getPath(root, q);
        int i = 0, j = 0;
        while (i < path_p.size() && j < path_q.size() && path_p[i] == path_q[j]) {
            ++i;
            ++j;
        }
        return path_p[i-1];
    }
};

class Solution1{
public:
    // p和q同时遍历，如果当前节点值大于p和q的值，说明p和q在当前节点的右子树；
    // 如果当前节点的值小于p和q的值，说明p和q在当前节点的左子树；
    // 如果p和q的值不满足以上情况，说明当前节点是分叉点，就是所要找的p和q的最近公共节点
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            } else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            } else {
                break;
            }
        }
        return ancestor;
    }
};