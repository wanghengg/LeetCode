#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* head = new ListNode(-1);
        ListNode* result = head;
        ListNode* first = l1, *second = l2;
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                head->next = new ListNode(first->val);
                first = first->next;
                head = head->next;
            } else {
                head->next = new ListNode(second->val);
                second = second->next;
                head = head->next;
            }
        }
        if (first == nullptr) head->next = second;
        if (second == nullptr) head->next = first;
        return result->next;
    }
};
