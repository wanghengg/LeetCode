#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0) , next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution{
public:
    void reverseLinkedList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        // 到达left节点前面一个节点
        ListNode* pre = dummyNode;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        // 到达right节点后面一个节点，rightNode表示需要翻转子链表的最后一个节点
        ListNode* rightNode = pre;
        for (int i = 0; i < right - left + 1; ++i) {
            rightNode = rightNode->next;
        }

        // leftNode表示要反转子链表的第一个节点
        ListNode* leftNode = pre->next;
        // curr表示待反转链表最后一个节点的后面一个节点
        ListNode* curr = rightNode->next;

        // 切断连接
        pre->next = nullptr;
        rightNode->next = nullptr;

        // 反转链表
        reverseLinkedList(leftNode);
        pre->next = rightNode;
        leftNode->next = curr;
        return dummyNode->next;
    }
};