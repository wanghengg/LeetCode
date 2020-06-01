//
// Created by wangheng on 2020/6/1.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
};

// 双指针
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head, *second = head;
        while (n--)
            second = second->next;
        if (second == nullptr)
            return head->next;
        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
    }
};