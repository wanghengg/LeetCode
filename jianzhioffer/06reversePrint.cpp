#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> temp;
        while (head) {
            temp.push(head->val);
            head = head->next;
        }
        while (!temp.empty()) {
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
};

int main() {
    auto* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    Solution solution;
    vector<int> res = solution.reversePrint(head);
    for(auto& iter : res) {
        cout << iter << ' ';
    }
    return 0;
}