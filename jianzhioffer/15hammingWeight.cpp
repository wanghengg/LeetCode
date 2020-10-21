#include <iostream>
using namespace std;

class Solution{
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    cout << solution.hammingWeight(10) << endl;
    return 0;
}