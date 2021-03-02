#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        int left = 0, right = length - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution solution;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s);
    for(auto& iter : s) {
        cout << iter << ' ';
    }
    return 0;
}