#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] == nums[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};