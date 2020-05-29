## 1-Two Sum

> 给定一个整数数组 `nums`和一个目标值 `target`，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
>
> 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
>
> 示例：
>
> ```
> 给定 nums = [2, 7, 11, 15], target = 9
> 
> 因为 nums[0] + nums[1] = 2 + 7 = 9
> 所以返回 [0, 1]
> 
> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/two-sum
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
> ```

```c++
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    for (auto first = nums.cbegin(); first != nums.cend(); ++first) {
        auto second = std::find(first + 1, nums.cend(), target - *first);
        if (second != nums.cend())
            return {static_cast<int>(first - nums.cbegin()), static_cast<int>(second - nums.cbegin())};
    }
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto result = twoSum(nums, target);
    for (auto iter : result)
        std::cout << iter << ' ';
    return 0;
}
```

## 7-Reverse Integer

> 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
>
> 示例1：
>
> ```
> 输入: 123
> 输出: 321
> ```
>
> 示例2：
>
> ```
> 输入: -123
> 输出: -321
> ```
>
> 示例3：
>
> ```
> 输入: 120
> 输出: 21
> ```

```c++
//
// Created by wangheng on 2020/5/27.
//

#include <iostream>
#include <climits>

class Solution{
public:
    int reverse(int x) {
        long long result = 0;
        while (x) {
            result = 10 * result + x % 10;
            x = x / 10;
            if (result < INT_MIN || result > INT_MAX) {
                result = 0;
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::cout << solution.reverse(1299999999) << std::endl;

    return 0;
}
```

## 190-Reverse Bits

> 颠倒给定的 32 位无符号整数的二进制位。
>
> 示例1：
>
> ```
> 输入: 00000010100101000001111010011100
> 输出: 00111001011110000010100101000000
> 解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
>      因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
> ```
>
> 示例2：
>
> ```
> 输入：11111111111111111111111111111101
> 输出：10111111111111111111111111111111
> 解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
>      因此返回 3221225471 其二进制表示形式为 10111111111111111111111111111111 。
> ```

```c++
//
// Created by wangheng on 2020/5/27.
//

#include <iostream>
#include <bitset>

class Solution{
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::cout << std::bitset<sizeof(uint32_t)*8>(solution.reverseBits(43261596)) << std::endl;

    return 0;
}
```

## 191-Number Of 1 Bits

> 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
>
> 示例1：
>
> ```
> 输入：00000000000000000000000000001011
> 输出：3
> 解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
> ```
>
> 示例2：
>
> ```
> 输入：00000000000000000000000010000000
> 输出：1
> 解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
> ```
>
> 示例3：
>
> ```
> 输入：11111111111111111111111111111101
> 输出：31
> 解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
> ```

```c++
//
// Created by wangheng on 2020/5/27.
//

#include <iostream>

class Solution{
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            result += (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::cout << solution.hammingWeight(11) << std::endl;

    return 0;
}
```

## 198-House Robber

> 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。**
>
> 给定一个代表每个房屋存放金额的非负整数数组，计算你**不触动警报装置的情况下**，一夜之内能够偷窃到的最高金额。
>
> 示例1：
>
> ```
> 输入: [1,2,3,1]
> 输出: 4
> 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
>      偷窃到的最高金额 = 1 + 3 = 4 。
> ```
>
> 示例2：
>
> ```
> 输入: [2,7,9,3,1]
> 输出: 12
> 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
>      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
> ```

首先考虑最简单的情况。如果只有一间房屋，则偷窃该房屋，可以偷窃到最高总金额。如果只有两间房屋，则由于两间房屋相邻，不能同时偷窃，只能偷窃其中的一间房屋，因此选择其中金额较高的房屋进行偷窃，可以偷窃到最高总金额。

如果房屋数量大于两间，应该如何计算能够偷窃到的最高总金额呢？对于第 k (k>2) 间房屋，有两个选项：

1. 偷窃第k间房屋，那么就不能偷窃第 k−1 间房屋，偷窃总金额为前 k−2 间房屋的最高总金额与第 k 间房屋的金额之和。

2. 不偷窃第 k 间房屋，偷窃总金额为前 k-1间房屋的最高总金额。

在两个选项中选择偷窃总金额较大的选项，该选项对应的偷窃总金额即为前 k 间房屋能偷窃到的最高总金额。

用`dp[i]`表示前i间房屋能偷窃到的最高总金额，那么就有如下的状态转移方程：

$$dp[i]=max(dp[i-2]+nums[i], dp[i-1])$$

边界条件为：

$$\begin{cases}dp[0] = nums[0] & 只有一间房屋，则偷窃该房屋 \\ dp[1]=max(nums[0], nums[1]) & 只有两间房屋时，选择其中金额较高的房屋进行偷窃\end{cases}$$


最终的答案即为 $$dp[n-1]$$，其中 n 是数组的长度。

```c++
//
// Created by wangheng on 2020/5/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 动态规划+滚动数组，时间复杂度O(n)，空间复杂度O(1)
 *
 * 首先考虑最简单的情况。如果只有一间房屋，则偷窃该房屋，可以偷窃到最高总金额。如果只有两间房屋，
 * 则由于两间房屋相邻，不能同时偷窃，只能偷窃其中的一间房屋，因此选择其中金额较高的房屋进行偷窃，
 * 可以偷窃到最高总金额。
 * 如果房屋数量大于两间，应该如何计算能够偷窃到的最高总金额呢？对于第 k~(k>2)k (k>2) 间房屋，
 * 有两个选项：
 * 
 */
class Solution{
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> states(n, 0);
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int temp = second;
            second = max(second, first + nums[i]);
            first = temp;
        }
        return second;
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,3,2,9};
    cout << solution.rob(nums) << endl;

    return 0;
}z`
```

## 1051-Height Checker

> 学校在拍年度纪念照时，一般要求学生按照 非递减 的高度顺序排列。
>
> 请你返回能让所有学生以 非递减 高度排列的最小必要移动人数。
>
> 注意，当一组学生被选中时，他们之间可以以任何可能的方式重新排序，而未被选中的学生应该保持不动。
>
> 示例1：
>
> ```
> 输入：heights = [1,1,4,2,1,3]
> 输出：3 
> 解释：
> 当前数组：[1,1,4,2,1,3]
> 目标数组：[1,1,1,2,3,4]
> 在下标 2 处（从 0 开始计数）出现 4 vs 1 ，所以我们必须移动这名学生。
> 在下标 4 处（从 0 开始计数）出现 1 vs 3 ，所以我们必须移动这名学生。
> 在下标 5 处（从 0 开始计数）出现 3 vs 4 ，所以我们必须移动这名学生。
> ```
>
> 示例2：
>
> ```
> 输入：heights = [5,1,2,3,4]
> 输出：5
> ```
>
> 示例3：
>
> ```
> 输入：heights = [1,2,3,4,5]
> 输出：0
> ```

可以将`heights`排序，然后对比排序后的数组和排序前的数组，同一位置不相等的元素的个数就是需要调整的学生个数。

```c++
//
// Created by wangheng on 2020/5/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1{
public:
    int heightChecker(vector<int>& heights) {
        vector<int> origin(heights);
        stable_sort(heights.begin(), heights.end());
        int result = 0;
        int size = heights.size();
        for (int i = 0; i < size; ++i) {
            if (heights[i] != origin[i])
                result += 1;
        }
        return result;
    }
};

class Solution2{
public:
    int heightChecker(vector<int>& heights) {
        int* arr = new int[101]();
        for (auto &height : heights)
            arr[height]++;
        int result = 0;
        for (int i = 1, j = 0; i < 101; ++i) {
            while (arr[i]-- > 0) {
                if (heights[j++] != i)
                    ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution2 solution;
    vector<int> heights{1,1,4,2,1,3};
    cout << solution.heightChecker(heights) << endl;

    return 0;
}
```

