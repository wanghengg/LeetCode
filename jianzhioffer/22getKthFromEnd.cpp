#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 双指针，second指针先往后移动k个节点，然后first指针和second指针同时往后移动直到second指针到达尾结点，此时first指针刚好在倒数第k个节点
        if (head == nullptr) return head;
        ListNode* first = head, *second = head;
        while (k--) {
            second = second->next;
        }
        while (second) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};
