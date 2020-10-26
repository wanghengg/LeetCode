#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* mergerKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int length = lists.size();
        vector<int> value;
        // 将链表中所有的数据线保存在vvalue中
        for (int i = 0; i < length; i++) {
            ListNode* node = lists[i];
            while (node) {
                value.push_back(node->val);
                node = node->next;
            }
        }
        if (value.empty()) return nullptr;  // 如果value为空，则返回空指针
        sort(value.begin(), value.end());   // 对value进行排序
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        for (int i : value) {
            cur->next = new ListNode(i);
            cur = cur->next;
        }
        return head->next;
    }
};