//
// Created by wangheng on 2021/4/18.
//

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = 0, lengthB = 0;
        ListNode* curA = headA, *curB = headB;
        while (curA) {
            ++lengthA;
            curA = curA->next;
        }
        while (curB) {
            ++lengthB;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (lengthA > lengthB) {
            int diff = lengthA - lengthB;
            while (diff--) {
                curA = curA->next;
            }
        } else {
            int diff = lengthB - lengthA;
            while (diff--) {
                curB = curB->next;
            }
        }
        while (curA != nullptr && curB != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};