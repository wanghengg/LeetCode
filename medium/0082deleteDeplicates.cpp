#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // 哈希表
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> count;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        while (dummyHead->next) {
            count[dummyHead->next->val]++;
            dummyHead = dummyHead->next;
        }
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        for (auto& iter : count) {
            if (iter.second == 1) {
                res->next = new ListNode(iter.first);
                res = res->next;
            }
        }
        return cur->next;
    }


    // 注意链表本身是有序的，所以重复出现的数字一定连在一起，所以只用通过一次遍历就可以了，不需要哈希表
    ListNode* deleteDuplicates1(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};