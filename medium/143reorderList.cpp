#include <iostream>
#include <vector>
#include <deque>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
 * 因为链表的值不能直接访问，只能从head开始遍历，所以可以把链表的值遍历存在线性表里面，然后再
 * 重构链表
 */
class Solution{
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        vector<ListNode*> vec;
        ListNode* node = head;
        while (node) {
            vec.push_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) break;
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};

/*
 * 利用双向队列，将节点遍历保存在队列中，然后依次从头尾弹出
 */
class Solution1{
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        deque<ListNode*> que;
        ListNode* cur = head->next;
        while (cur) {
            que.push_back(cur);
            cur = cur->next;
        }
        cur = head;
        while (!que.empty()) {
            cur->next = que.back();
            que.pop_back();
            if (!que.empty()) {
                cur->next->next = que.front();
                que.pop_front();
                cur = cur->next->next;
            } else {
                cur = cur->next;
            }
            cur->next = nullptr;
        }
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution1 solution;
    solution.reorderList(head);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    return 0;
}