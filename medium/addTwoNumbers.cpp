//
// Created by wangheng on 2020/5/27.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result;
        ListNode* head = result;
        int carry = 0;
        int sum;
        while (true) {
            sum = l1->val + l2->val + carry;
            if (sum > 9) {
                head->val = sum % 10;
                carry = 1;
            } else {
                head->val = sum;
                carry = 0;
            }
            if (l1->next == nullptr && l2->next == nullptr)
                break;
            if (l1->next != nullptr)
                l1 = l1->next;
            else
                l1->val = 0;
            if (l2->next != nullptr)
                l2 = l2->next;
            else
                l2->val = 0;
        }
//        if (getLength(l1) >= getLength(l2))
//            head = l1;
//        else
//            head = l2;
    }

//    int getLength(ListNode* l) {
//        int length = 0;
//        while (l->next != nullptr)
//            ++length;
//        return ++length;
//    }
};

int main() {

}