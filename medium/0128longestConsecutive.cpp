//
// Created by wangheng on 2021/5/30.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (auto& iter : nums) {
            num_set.insert(iter);   // 去除重复元素
        }

        int longestStreak = 0;  // 最大连续序列
        for (auto& iter : num_set) {    // 遍历每个元素查找以其开始的最长连续序列
            if (!num_set.count(iter-1)) {   // 如果当前数字有比其小1的元素，直接跳过，因为由该数字开始的最长序列一定比以比其小的数字开始的最长序列短(剪枝)
                int currentNum = iter;  // 当前迭代的数字
                int currentStreak = 1;  // 以当前数字开头的序列长度

                while (num_set.count(currentNum+1)) {   // 当有后继数字的时候，当前序列长度+1
                    currentStreak += 1;
                    currentNum += 1;
                }
                longestStreak = max(longestStreak, currentStreak);  // 比较得到最大连续序列长度
            }
        }
        return longestStreak;
    }
};

/*
 * 并查集
 * 初始时将每个数组里的元素初始化为他的下一个数
 * 并的时候找到他能达到的最远的数字
 */

class Solution1{
public:
    unordered_map<int, int> a;
    unordered_set<int> num_set;
    int find(int x) {
        return a.count(x) ? find(a[x]) : x; // 如果下一个数存在递归寻找下一个数的下一个数，如果不存在直接返回当前数
    }

    int longestConsecutive(vector<int>& nums) {
        for (auto& iter : nums) {
            num_set.insert(iter);
        }
        for (auto& iter : num_set) {
            a[iter] = iter + 1;
        }
        int ans = 0;
        for (auto& iter : num_set) {
            if (!num_set.count(iter-1)) {
                int y = find(iter);
                ans = max(ans, y - iter);
            }
        }
        return ans;
    }
};

int main() {
    Solution1 solution;
    vector<int> nums{100, 4, 200, 1, 3, 2};
    cout << solution.longestConsecutive(nums) << endl;

    return 0;
}