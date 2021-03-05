#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* middleNode(ListNode* head) {
        // 用快慢指针，慢指针每次移动一个节点，快指针每次移动两个节点，最终快指针到尾结点的时候慢指针到中间节点
        ListNode* first = head, *second = head;
        while(second->next) {
            if (second->next->next == nullptr) return first->next;
            first = first->next;
            second = second->next->next;
        }
        return first;
    }
};

class Base
{
public:
    virtual void fun ( int x = 10 )
    {
        cout << "Base::fun(), x = " << x << endl;
    }
};

class Derived : public Base
{
public:
    virtual void fun ( int x=20 )
    {
        cout << "Derived::fun(), x = " << x << endl;
    }
};


int main()
{
    Derived d1;
    Base *bp = &d1;
    bp->fun();  // 10
    return 0;
}
