#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec{
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";
        queue<TreeNode*> q;
        string result = "[";
        q.emplace(root);
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (front == nullptr) {
                result += "null,";
            } else {
                result += to_string(front->val);
                result += ",";
                q.push(front->left);
                q.push(front->right);
            }
        }
        result[result.size()-1] = ']';
        return result;
    }

    TreeNode* deserialize(string data) {
        vector<string> rec;
        if (data.size() == 2) return nullptr;
        int i = 1, j = 1;
        while (i < data.size()-1) {
            if (data[i] != ',') {
                ++i;
            } else {
                string tmp = data.substr(j, i - j);
                rec.emplace_back(tmp);
                ++i;
                j = i;
            }
        }
        if (j != i) {
            string tmp = data.substr(j, i - j);
            rec.emplace_back(tmp);
        }

        TreeNode* root = new TreeNode(stoi(rec[0]));
        queue<TreeNode*> q;
        q.emplace(root);
        i = 1;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (rec[i] != "null") {
                front->left = new TreeNode(stoi(rec[i]));
                q.emplace(front->left);
            }
            ++i;
            if (rec[i] != "null") {
                front->right = new TreeNode(stoi(rec[i]));
                q.emplace(front->right);
            }
            ++i;
        }
        return root;
    }
};

int main() {
    Codec solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string  result = solution.serialize(root);
    cout << result << endl;

    TreeNode* head = solution.deserialize(result);

    return 0;
}