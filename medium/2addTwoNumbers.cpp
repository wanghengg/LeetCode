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
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0;
        int sum;
        while (head1->next != nullptr && head2->next != nullptr) {
            sum = head1->val + head2->val + carry;
            if (sum > 9) {
                head1->val = sum % 10;
                carry = 1;
            } else {
                head1->val = sum;
                carry = 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        if (head1->next == nullptr && head2->next != nullptr) {
            head1->next = head2->next;
            sum = head1->val + head2->val + carry;
            if (sum > 9) {
                head1->val = sum % 10;
                carry = 1;
            } else {
                head1->val = sum;
                carry = 0;
            }
            while (head1->next != nullptr) {
                head1 = head1->next;
                if ((head1->val + carry) > 9) {
                    head1->val = 0;
                    carry = 1;
                } else {
                    head1->val = head1->val + carry;
                    carry = 0;
                    break;
                }
            }
            if (carry == 1)
                head1->next = new ListNode(carry);
            return l1;
        }

        if (head1->next != nullptr && head2->next == nullptr) {
            sum = head1->val + head2->val + carry;
            if (sum > 9) {
                head1->val = sum % 10;
                carry = 1;
            } else {
                head1->val = sum;
                carry = 0;
            }
            while (head1->next != nullptr) {
                head1 = head1->next;
                if ((head1->val + carry) > 9) {
                    head1->val = 0;
                    carry = 1;
                } else {
                    head1->val = head1->val + carry;
                    carry = 0;
                    break;
                }
            }
            if (carry == 1)
                head1->next = new ListNode(carry);
            return l1;
        }

        if (head1->next == nullptr && head2->next == nullptr) {
            sum = head1->val + head2->val + carry;
            if (sum > 9) {
                head1->val = sum % 10;
                carry = 1;
            } else {
                head1->val = sum;
                carry = 0;
            }
            if (carry == 1)
                head1->next = new ListNode(carry);
            return l1;
        }
        return l1;
    }
};

int main() {
    Solution solution;
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(8);
    ListNode* l2 = new ListNode(1);
    ListNode* result = solution.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        std::cout << result->val << ' ';
        result = result->next;
    }

    return 0;
}