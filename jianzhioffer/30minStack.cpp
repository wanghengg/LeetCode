#include <iostream>
#include <stack>

using namespace std;

// 要想达到min操作时间复杂度为O(1)，只能用空间换取时间
class MinStack{
private:
    stack<int> mainStack;   // 用于存储数据，保证push,pop,top操作时间复杂度为O(1)
    stack<int> auxiliaryStack;  // 用于保存最小数据，每次只将最小数入栈，保证栈顶始终是最小值

public:
    MinStack() {}

    void push(int x) {
        if (auxiliaryStack.empty()) // 当辅助栈为空时，应该直接将值压入
            auxiliaryStack.push(x);
        else if (x <= auxiliaryStack.top())
            auxiliaryStack.push(x);
        mainStack.push(x);
    }

    void pop() {
        if (mainStack.empty()) return;
        if (mainStack.top() == auxiliaryStack.top())
            auxiliaryStack.pop();
        mainStack.pop();
    }

    int top() {
        if (mainStack.empty()) return -1;
        return mainStack.top();
    }

    int min() {
        return auxiliaryStack.top();
    }
};

int main() {
    MinStack *minStack = new MinStack();
    minStack->push(646);
    minStack->push(646);
    minStack->push(647);
    cout << minStack->top() << endl;
    minStack->pop();
    cout << minStack->min() << endl;
    minStack->pop();
    cout << minStack->min() << endl;
    minStack->pop();
    minStack->push(647);
    cout << minStack->top() << endl;
    cout << minStack->min() << endl;
    minStack->push(-648);
    cout << minStack->top() << endl;
    cout << minStack->min() << endl;
    minStack->pop();
    cout << minStack->min() << endl;

    return 0;
}