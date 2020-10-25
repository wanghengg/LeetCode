#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> result;
        if (A.empty()) return result;
        unordered_map<char, int> times;
        // 将A[0]中所有的元素和相应出现的次数保存至times里面
        for (auto& it : A[0]) {
            times[it]++;
        }
        for (auto& pair : times) {  // 对times里面的每个字符都在其他字符串里面查找其出现次数
            int occurNums = pair.second;
            for (int i = 1; i < A.size(); i++) {
                int tmp = count(A[i].begin(), A[i].end(), pair.first); // 查找出现次数
                occurNums = min(occurNums, tmp);    // 如果出现，应该保存和当前occurNums相比最小的次数
            }
            while (occurNums--) {
                result.push_back(string{pair.first});
            }
        }
        return result;
    }
};

int main() {
    vector<string> A{"", "label", "roller"};
    Solution solution;
    vector<string> result = solution.commonChars(A);
    for (auto& iter : result) {
        cout << iter << ' ';
    }
    return 0;
}