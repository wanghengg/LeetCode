//
// Created by wangheng on 2020/5/30.
//

#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1{
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL){
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};

class Solution2{
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* result = nullptr;
        while (head) {
            ListNode* temp = new ListNode(head->val);
            temp->next = result;
            result = temp;
            head = head->next;
        }
        return result;
    }
};