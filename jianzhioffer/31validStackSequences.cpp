#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
    bool validStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty() && popped.empty()) return true;
        if (pushed.size() != popped.size()) return false;
        stack<int> numbers;
        int index = 0;
        for (auto& iter : pushed) {
            numbers.push(iter);
            while (!numbers.empty() && numbers.top() == popped[index]) {
                numbers.pop();
                ++index;
            }
        }
        return numbers.empty();
    }
};

int main() {
    vector<int> pushed{1,2,3,4,5};
    vector<int> popped{4,5,3,2,1};
    Solution solution;
    cout << boolalpha << solution.validStackSequences(pushed, popped) << endl;

    return 0;
}