//
// Created by wangheng on 2020/6/2.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* prevHead = new ListNode(-1);
        ListNode* prev = prevHead;
        while(head != nullptr && head->next !=nullptr) {
            // 记录下下个节点，否则会陷入循环
            ListNode* succ = head->next->next;
            prev->next = head->next;
            prev = prev->next;
            prev->next = head;
            head = succ;
            prev = prev->next;
        }
        prev->next = head;

        return prevHead->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution solution;
    ListNode* result = solution.swapPairs(head);
    while (result != nullptr) {
        std::cout << result->val << ' ';
        result = result->next;
    }

    return 0;
}