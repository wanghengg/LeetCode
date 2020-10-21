#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) return head;
        if (head->val == val) return head->next;
        ListNode* tmp = head;
        while (head->next) {
            if (head->next->val == val) {
                head->next = head->next->next;
                break;
            } else {
                head = head->next;
            }
        }
        return tmp;
    }
};