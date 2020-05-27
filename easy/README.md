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

