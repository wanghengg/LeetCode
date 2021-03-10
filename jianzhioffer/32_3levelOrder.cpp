#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
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
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        int count = 0;
        while (!que.empty()) {
            int len = que.size();
            vector<int> level;
            ++count;
            while (len--) {
                TreeNode* front = que.front();
                que.pop();
                level.push_back(front->val);
                if (front->left) que.push(front->left);
                if (front->right) que.push(front->right);
            }
            if (count % 2 == 0) {   // 偶数层将该层数组反转
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
        }
        return res;
    }

    // 奇数层从后面添加进双端队列，偶数层从前面添加进双端队列
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if (root == nullptr) return {};
        deque<TreeNode*> deq;
        deq.push_back(root);
        int count = 1;
        vector<vector<int>> res;
        while (!deq.empty()) {
            int len = deq.size();
            vector<int> level;
            ++count;
            if (count % 2 == 1) {
                while (len--) {
                    TreeNode *front = deq.front();
                    deq.pop_front();
                    level.push_back(front->val);
                    if (front->left) deq.push_back(front->left);
                    if (front->right) deq.push_back(front->right);
                }
            } else {
                while (len--) {
                    TreeNode* back = deq.back();
                    deq.pop_back();
                    level.push_back(back->val);
                    if (back->right) deq.push_front(back->right);
                    if (back->left) deq.push_front(back->left);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Solution solution;
    vector<vector<int>> res = solution.levelOrder1(root);
    return 0;
}