#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


// 哈希表法，但是空间复杂度为O(n)
class Solution{
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> hashSet;
        while (head) {
            if (hashSet.count(head)) {
                return true;
            } else {
                hashSet.insert(head);
                head = head->next;
            }
        }
        return false;
    }
};

// 快慢指针法，一个快指针每次移动两步，一个慢指针一次移动一步，如果没有环那么快指针将最快到达
// 链表尾部结束，如果有环，快指针会套圈，最终慢指针超过快指针
class Solution2{
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};