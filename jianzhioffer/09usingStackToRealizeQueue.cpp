#include <iostream>
#include <stack>
using namespace std;

class CQueue{
public:
    stack<int> stack1, stack2;
    CQueue() {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        // 如果stack2空，那么将stack1里面的所有元素移至stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            return -1;
        } else {
            int value = stack2.top();
            stack2.pop();
            return value;
        }
    }
};