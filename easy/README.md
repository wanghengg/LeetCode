## twoSum

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

## reverseInteger

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

## reverseBits

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

## numberOf1Bits

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

