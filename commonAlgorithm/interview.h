#ifndef LEETCODE_INTERVIEW_H
#define LEETCODE_INTERVIEW_H

#include <bits/stdc++.h>
using namespace std;

void *memcpy(void* dst, const void* src, unsigned int count) {
    void *ret = dst;
    while (count--) {
        *(char *)dst = *(char *)src;   // 不能直接对void解引用
        dst = (char *)dst + 1;  // 不能直接对void指针加1
        src = (char *)src + 1;
    }
    return ret;
}

void *memmove(void* dst, const void* src, unsigned int count) {
    void *ret = dst;
    if (dst < src || (char *)dst >= (char *)src + count) {  // 没有重叠或者重叠但是不影响
        while (count--) {
            *(char *)dst = *(char *)src;
            dst = (char *)dst + 1;
            src = (char *)src + 1;
        }
    } else {
        dst = (char *)dst + count - 1;
        src = (char *)src + count - 1;
        while (count--) {
            *(char *)dst = *(char *)src;
            dst = (char *)dst - 1;
            src = (char *)src - 1;
        }
    }
    return ret;
}

int atoi(const char* p) {

}

/*
 * 二叉树的前、中、后序遍历
 */
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 前序遍历，递归法
void preorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    res.emplace_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
}

// 前序遍历，迭代法1
vector<int> preorderTraversal1(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
        auto top = stack.top();
        res.emplace_back(top->val);
        stack.pop();
        if (top->right) stack.push(top->right); // 栈先入后出，所以右节点先入栈
        if (top->left) stack.push(top->left);
    }
    return res;
}

// 前序遍历，迭代法2
vector<int> preorderTraversal2(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<TreeNode*> stack;
    while (!stack.empty() || root != nullptr) {
        while (root != nullptr) {   // 如果节点不为nullptr，那么每次先访问左子节点
            res.emplace_back(root->val);
            stack.push(root);
            root = root->left;
        }
        auto top = stack.top();
        root = top->right;
        stack.pop();
    }
    return res;
}

// 中序遍历，递归法
void inorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    inorder(root->left, res);
    res.emplace_back(root->val);
    inorder(root->right, res);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

// 中序遍历，迭代法
vector<int> inorderTraversal1(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stack;
    while (!stack.empty() || root != nullptr) {
        while (root != nullptr) {   // 如果节点不为nullptr，将左节点压入栈
            stack.push(root);
            root = root->left;
        }
        // 直到沿着最左边一趟没有左子节点
        auto top = stack.top();
        res.emplace_back(top->val);
        stack.pop();
        root = top->right;
    }
    return res;
}

// 后序遍历，递归写法
void postorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.emplace_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root, res);
    return res;
}

// 后序遍历，迭代写法1
/*
 * 先序遍历的顺序是中左右，后序遍历是左右中，可以改变一下先序遍历为中右左，然后反转遍历数组就是后序遍历的结果了
 */
vector<int> postorderTraversal1(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stack;
    while (!stack.empty() || root != nullptr) {
        while (root != nullptr) {
            res.emplace_back(root->val);
            stack.push(root);
            root = root->right;
        }
        auto top = stack.top();
        stack.pop();
        root = top->left;
    }
    reverse(res.begin(), res.end());
    return res;
}

// 后序遍历，迭代写法2
vector<int> postorderTraversal2(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stack;
    TreeNode* prev = nullptr;
    while (!stack.empty() || root != nullptr) {
        while (root != nullptr) {
            stack.emplace(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        if (root->right == nullptr || root->right == prev) {
            res.emplace_back(root->val);
            prev = root;
            root = nullptr;
        } else {
            stack.emplace(root);
            root = root->right;
        }
    }
    return res;
}

#endif //LEETCODE_INTERVIEW_H
