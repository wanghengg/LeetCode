#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
 * 对字符串S进行遍历，开始查找最后一个等于S[0]的位置，则划分的第一个片段至少为s[0]到查找到的最后一个S[0]位置，
 * 然后继续查找S[1]出现的最后一个位置，如果S[1]出现的最后一个未知在S[0]出现的最后一个位置之前，继续查找S[2]
 * 的最后一个位置，若查找到的S[1]的最后一个位置在查找到的S[0]的最后一个位置之后，那么第一个片段的范围为S[0]到
 * S[1]的最后一个位置，以此类推...
 * 将已经查询的字符放在一个vector里面，如果后续查找的字符已经查找过，则不必继续查找
 */
class Solution{
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int length = 0;
        int start = 0;
        for(int i = 0; i < S.size(); i++) {
            unordered_set<char> fought;
            if (fought.count(S[i])) continue;
            auto last = find_end(S.begin(), S.end(), S.begin()+i, S.begin()+i+1);
            length = (last - S.begin() - start + 1 > length) ? last - S.begin() - start + 1 : length;
            fought.insert(S[i]);
            if (S.begin() + i == S.begin() + length + start - 1) {
                res.push_back(length);
                fought.clear();
                length = 0;
                start = i + 1;
            }
        }
        return res;
    }
};

int main() {
    string S = "ababcbacadefegdehijhklij";
    Solution solution;
    vector<int> res = solution.partitionLabels(S);
    for (auto& iter : res) {
        cout << iter << ' ';
    }
    return 0;
}