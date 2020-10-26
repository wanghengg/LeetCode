#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution{
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            Node* nextLine = bfs.front()->left; // 下一行的第一个节点元素
            if (nextLine != nullptr) {  // 如果存在下一行
                while (bfs.front() != nextLine) {   // bfs的首个元素不是下一行的第一个节点指针，说明此行还没有结束
                    Node *front = bfs.front();
                    if (front->left) bfs.push(front->left); // 将front的左子节点压入队列
                    if (front->right) bfs.push(front->right);   // 将front的右子节点压入队列
                    bfs.pop();
                    if (nextLine == bfs.front()) {
                        front->next = nullptr;  // 如果队列的首个元素不等于下一行的第一个节点，则此行没有结束，新弹出节点的next节点为队列的第一节点
                    } else {
                        front->next = bfs.front();  // 如果队列的首个元素等于下一行的第一个节点，说明此行结束，新弹出节点的next节点为nullptr
                    }
                }
            } else {    // 如果nextLine为空指针，即当前行是最后一行，则按顺序弹出队列中所有的元素，每弹出一个节点的next节点为队列的弹出后队列的首个节点
                Node* front = bfs.front();
                bfs.pop();
                while (!bfs.empty()) {
                    front->next = bfs.front();
                    front = bfs.front();
                    bfs.pop();
                }
                front->next = nullptr;
            }
        }
        return root;
    }
};

class Solution1{
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int len = bfs.size();
            while (len--) {
                Node* front = bfs.front();
                if (front->left) bfs.push(front->left);
                if (front->right) bfs.push(front->right);
                bfs.pop();
                if (len == 0) {
                    front->next = nullptr;
                } else {
                    front->next = bfs.front();
                }
            }
        }
        return root;
    }
};