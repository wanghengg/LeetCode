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
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* result = head->next;
        ListNode* first = head;
        ListNode* second = first->next;
        ListNode* header = new ListNode(0);
        while (first != nullptr && second != nullptr) {
            first->next = first->next->next;
            ListNode* temp = first;
            first = second;
            first->next = temp;
            second = first->next;
            header->next = first;
            header = second;
            if (second->next == nullptr || second->next->next == nullptr)
                break;
            first = first->next->next;
            second = first->next;
        }
        return result;
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