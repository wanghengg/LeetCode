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
        int start = 0;  // 标记每个划分段起始位置
        for(int i = 0; i < S.size(); i++) {
            unordered_set<char> fought; // 将已经查找过的字符放在里面，避免重复查找
            if (fought.count(S[i])) continue;   // 如果当前字符查找过，则跳过查找下一个字符
            auto last = find_end(S.begin(), S.end(), S.begin()+i, S.begin()+i+1);   // 被查找字符出现的最后一个位置

            // 如果当前查找的字符位置在之前查找位置之后，更新划分段的长度
            length = (last - S.begin() - start + 1 > length) ? last - S.begin() - start + 1 : length;
            fought.insert(S[i]);    // 将已经查找过的字符添加入fought

            // 如果当前查找的字符已经是当前划分段的最后一个字符，则说明此段结束，将此段长度
            // 添加至res中，然后将段长length重置为0，并将start更新为下一段的第一个字符的位置
            // 同时将fought清空，用于保存下一段已经查询过的字符
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

/*
 * 贪心算法+双指针
 */
class Solution1{
public:
    vector<int> partitionLabels(string S) {
        int last[26];   // 保存26个字母最右端的位置
        int length = S.size();
        for (int i = 0; i < length; i++) {
            last[S[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0; // 双指针，start指向开始，end指向结束
        for (int i = 0; i < length; i++) {
            end = max(end, last[S[i] - 'a']);   // S[i]最后出现的位置如果比end更大，那么更新end
            if (i == end) { // 知道end等于i，此时说明此段结束，将此段长度保存，将start设置为end+1，继续
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};

int main() {
    string S = "ababcbacadefegdehijhklij";
    Solution1 solution;
    vector<int> res = solution.partitionLabels(S);
    for (auto& iter : res) {
        cout << iter << ' ';
    }
    return 0;
}