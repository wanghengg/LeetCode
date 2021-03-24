#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList{
    int size;   // 链表长度
    ListNode* head; // 哨兵节点
public:
    MyLinkedList() : size(0), head(new ListNode()) {}

    int get(int index) {
        if (index >= size || index < 0) return -1;
        ListNode* res = head;
        while (index--) {
            res = res->next;
        }
        return res->next->val;
    }

    void addAtHead(int val) {
        ListNode* next = head->next;
        head->next = new ListNode(val);
        head->next->next = next;
        ++size;
    }

    void addAtTail(int val) {
        ListNode* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new ListNode(val);
        ++size;
    }

    void addAtIndex(int index, int val) {
        if (index == size) addAtTail(val);
        if (index < 0) addAtHead(val);
        if (index >= 0 && index < size) {
            ListNode* tmp = head;
            while (index--) {
                tmp = tmp->next;
            }
            ListNode* next = tmp->next;
            tmp->next = new ListNode(val);
            tmp->next->next = next;
            ++size;
        }
        if (index > size) return;
    }

    void deleteAtIndex(int index) {
        if (index >= 0 && index < size) {
            ListNode* tmp = head;
            while (index--) {
                tmp = tmp->next;
            }
            ListNode* node = tmp->next;
            tmp->next = tmp->next->next;
            delete node;
            --size;
        }
    }
};