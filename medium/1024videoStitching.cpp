#include <iostream>
#include <vector>
using namespace std;

/*
 * 动态规划，dp[i]表示将区间[0,i)覆盖所需要的最少子区间的数量。
 */
class Solution{
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1); // 最开始初始化为最大整数
        dp[0] = 0;
        for (int i = 1; i <= T; i++) {
            // 计算dp[i]，也即覆盖[0,i)的最小区间个数
            for (auto& it : clips) {
                if (it[0] < i && i <= it[1]) {
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};

/*
 * 贪心算法
 */
class Solution1{
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
         vector<int> maxn(T);   // 对于每一个位置 i，记录以其为左端点的子区间中最远的右端点，记为maxn[i]
         int last = 0, ret = 0, pre = 0;
         for (vector<int>& it : clips) {
             if (it[0] < T) {
                 maxn[it[0]] = max(maxn[it[0]], it[1]); // 计算以位置i为起点的区间的最大右端点位置
             }
         }

         for (int i = 0; i < T; i++) {
             last = max(last, maxn[i]); // 每次更新last
             if (i == last) {   // 如果更新后的last等于i，说明下一个位置无法被覆盖
                 return -1;
             }
             // pre记录上一个被使用的子区间的结束位置，每次越过一个被使用的子区间，就说明要启用一个新的区间，
             // 这个新的区间结束位置即为当前的last，同时需要让结果ret加1
             if (i == pre) {
                 ret++;
                 pre = last;
             }
         }
        return ret;
    }
};

int main() {
    Solution1 solution;
    vector<vector<int>> clips{{0,2}, {4,6}, {8,10}, {1,9}, {1,5}, {5,9}};
    int T = 10;
    cout << solution.videoStitching(clips, T) << endl;

    return 0;
}