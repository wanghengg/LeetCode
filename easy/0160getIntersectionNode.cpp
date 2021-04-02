#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : vaL(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA) {
            ++lengthA;
            curA = curA->next;
        }
        while (curB) {
            ++lengthB;
            curB = curB->next;
        }

        int diff = lengthA - lengthB;
        if (diff > 0) {
            ListNode* listA = headA;
            ListNode* listB = headB;
            while (diff--) {
                listA = listA->next;
            }
            while (listA != nullptr && listB != nullptr) {
                if (listA == listB) {
                    return listA;
                } else {
                    listA = listA->next;
                    listB = listB->next;
                }
            }
        } else if (diff < 0) {
            diff = -diff;
            ListNode* listA = headA;
            ListNode* listB = headB;
            while (diff--) {
                listB = listB->next;
            }
            while (listA != nullptr && listB != nullptr) {
                if (listA == listB) {
                    return listA;
                } else {
                    listA = listA->next;
                    listB = listB->next;
                }
            }
        } else {
            ListNode* listA = headA;
            ListNode* listB = headB;
            while (listA != nullptr && listB != nullptr) {
                if (listA == listB) {
                    return listA;
                } else {
                    listA = listA->next;
                    listB = listB->next;
                }
            }
        }
        return nullptr;
    }
};