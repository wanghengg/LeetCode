#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string partialCalculate(stack<char> partial) {
        int sum = 0;
        while (!partial.empty()) {
            int tmp = 0;    // 被符号分割的数字
            char positiveOrNegative = '+';
            if (partial.top() == '+' || partial.top() == '-') {
                positiveOrNegative = partial.top();
                partial.pop();
            }
            while (!partial.empty() && partial.top() != '+' && partial.top() != '-') {
                tmp = tmp * 10 + stoi(string{partial.top()});
                partial.pop();
            }
            if (positiveOrNegative == '+')
                sum += tmp;
            else
                sum -= tmp;
        }
        stringstream ss;
        ss << sum;
        string res;
        ss >> res;
        return res;
    }
    int calculate(string s) {
        stack<char> characters;
        for (auto& iter : s) {
            if (iter == ' ')
                continue;
            if (iter != ')')
                characters.push(iter);
            if (iter == ')') {
                stack<char> partial;
                while (characters.top() != '(') {
                    partial.push(characters.top());
                    characters.pop();
                }
                characters.pop();
                string tmp = partialCalculate(partial);
                if (!characters.empty()) {
                    if (tmp[0] == '-') {
                        if (characters.top() == '+') {
                            characters.pop();
                            for (auto& i : tmp) {
                                characters.push(i);
                            }
                        }
                        else {
                            characters.top() = '+';
                            for (auto& j : tmp.substr(1, tmp.size() - 1))
                                characters.push(j);
                        }
                    }
                    else {
                        for (auto& m : tmp) {
                            characters.push(m);
                        }
                    }
                }
                else {
                    for (auto& k : tmp)
                        characters.push(k);
                }
            }
        }
        stack<char> part;
        while (!characters.empty())
        {
            part.push(characters.top());
            characters.pop();
        }
        string res = partialCalculate(part);
        stringstream ss;
        ss << res;
        int sum;
        ss >> sum;
        return sum;
    }
};

int main() {
    Solution solution;
    string s = "(5-(1+(5)))";
    cout << solution.calculate(s) << endl;

    return 0;
}