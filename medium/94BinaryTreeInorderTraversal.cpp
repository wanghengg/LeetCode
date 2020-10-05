#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        while(true) {
            goAlongLeftBranch(root, s);
            if (s.empty()) break;
            root = s.top();
            s.pop();
            result.push_back(root->val);
            root = root->right;
        }

        return result;
    }

    void goAlongLeftBranch(TreeNode* x, stack<TreeNode*>& s) {
        while(x) {
            s.push(x);
            x = x->left;
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    for(auto iter : result) {
        cout << iter << '\t';
    }

    return 0;
}