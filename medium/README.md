## `addTwoNumbers`

> 给出两个**非空**的链表用来表示两个非负的整数。其中，它们各自的位数是按照**逆序**的方式存储的，并且它们的每个节点只能存储**一位** 数字。
>
> 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
>
> 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
>
> 示例：
>
> ```
> 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
> 输出：7 -> 0 -> 8
> 原因：342 + 465 = 807
> ```

## `countBits`

> 给定一个非负整数 **`num`**。对于 **0 ≤ i ≤ `num`** 范围中的每个数字 **i** ，计算其二进制数中的 1 的数目并将它们作为数组返回。
>
> 示例1：
>
> ```
> 输入: 2
> 输出: [0,1,1]
> ```
>
> 示例2：
>
> ```
> 输入: 5
> 输出: [0,1,1,2,1,2]
> ```

**暴力解法**，时间复杂度$$O(n*sizeof(int))$$，空间复杂度$$O(n)$$

```c++
//
// Created by wangheng on 2020/5/27.
//

#include <iostream>
#include <vector>
using namespace std;

int popCount(int x) {
    int count = 0;
    while (x > 0) {
        ++count;
        x &= (x - 1);
    }
    return count;
}

vector<int> countBits(int num) {
    vector<int> result;
    for (int i = 0; i <= num; ++i)
        result.push_back(popCount(i));
    return result;
}

int main() {
    for (auto iter : countBits(9))
        std::cout << iter << ' ';
    return 0;
}
```