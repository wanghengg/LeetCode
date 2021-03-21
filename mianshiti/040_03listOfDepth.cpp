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

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    // 层次遍历
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if (tree == nullptr) return vector<ListNode*>({nullptr});
        queue<TreeNode*> q;
        q.push(tree);
        vector<ListNode*> res;
        while (!q.empty()) {
            ListNode* head = new ListNode(-1);
            ListNode* pre = head;
            int len = q.size();
            while (len--) {
                TreeNode* front = q.front();
                q.pop();
                head->next = new ListNode(front->val);
                head = head->next;
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            res.push_back(pre->next);
        }
        return res;
    }
};