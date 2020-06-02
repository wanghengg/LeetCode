//
// Created by wangheng on 2020/5/27.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 时间复杂度为O(n)，只进行一次扫描
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0;
        int sum;
        while (head1->next != nullptr && head2->next != nullptr) {
            // 最终返回l1,用l1表示结果
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
        // 如果l1比l2短，用head1->next = head2->next将l2长出来的部分接在l1之后
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
                    // 在长出来的部分，如果某一位不进位，那么其后的每一位都不会进位，所以break
                    break;
                }
            }
            // 如果所有的加法做完之后，carry=1，说明最末位进位，需要增加一个节点，使其值为1，
            // 连接在末节点之后
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