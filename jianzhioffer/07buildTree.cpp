#include <iostream>
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        auto index = find(inorder.begin(), inorder.end(), preorder[0]);
        vector<int> left = vector<int>(inorder.begin(), index);
        vector<int> right = vector<int>(index, inorder.end());
    }
};