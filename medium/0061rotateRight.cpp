#include <bits/stdc++.h>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
};

using namespace std;
/*
 * 旋转1次，最后一个节点到第一个位置，旋转2次，倒数第二个节点到第一个位置，旋转n次，倒数第n个节点到第一个位置，
 * 考虑到旋转次数可能大于节点总数m，所以旋转n次，应该是倒数第n%m个节点是第一个节点，所以题目转换为找倒数第n%m
 * 个节点
 */
class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        // 先计算链表的节点数
        int count = 1;
        ListNode* cur = head;
        while (cur->next) {
            ++count;
            cur = cur->next;
        }
        cur->next = head;   // 把链表先连成环，最后找到倒数第n%m个从前面断开
        int m = k % count;  // 需要找到倒数第m个节点
        m = count - m;  // 实际就是找正数第count-m个节点
        ListNode* node = head;
        while (--m) {
            node = node->next;
        }
        ListNode* res = node->next;
        node->next = nullptr;
        return res;
    }
};