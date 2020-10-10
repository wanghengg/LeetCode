#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 哈希集合
class Solution{
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        while (head) {
            if (seen.count(head)) {
                return head;
            }
            seen.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

class Solution1{
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode* ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};