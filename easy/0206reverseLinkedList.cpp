//
// Created by wangheng on 2020/5/30.
//

#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 递归方法
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

// 迭代方法
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

// 双指针，起始时cur指向head，pre指向cur前面的一个节点
class Solution3{
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, *cur = head;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};