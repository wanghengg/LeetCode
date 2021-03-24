#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* tmp = pre;
        while (pre->next) {
            if (pre->next->val == val) {
                pre->next = pre->next->next;
            } else {
                pre = pre->next;
            }
        }
        return tmp->next;
    }
};