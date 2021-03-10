#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    // 判断以b为根的树是否为以a为根树的子结构
    bool recur(TreeNode* a, TreeNode* b) {
        if (b == nullptr) return true;  // b先递归到空，说明b被遍历完，返回true
        if (a == nullptr || a->val != b->val) return false; // 途中a遍历完或者a和b的val不等，则返回false
        return recur(a->left, b->left) && recur(a->right, b->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
