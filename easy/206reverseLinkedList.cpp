//
// Created by wangheng on 2020/5/30.
//

#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        if (head->next == nullptr || head == nullptr)
            return head;
        ListNode* headSub = reverseList(head->next);
        ListNode* result = headSub;
        while (headSub->next != nullptr)
            headSub = headSub->next;
        ListNode* temp = new ListNode(head->val);
        headSub->next = temp;
        return result;
    }
};