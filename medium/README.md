# 需要复习的题

[addTwoNumbers](#2Add-Two-Numbers)

[countBits](#338Counting-Bits)

## `2-Add Two Numbers`

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

## 338-Counting Bits

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

**迭代算法**

```c++
#include <iostream>
#include <vector>
using namespace std;

/*
 * i&(i-1)可以去掉i最右边的一个1(如果有的话)，因为i&(i-1)比i小，在前面已经计算出来，所以i
 * 的1的位数就是i&(i-1)的1的位数加1，时间复杂度为O(n)，空间复杂度为O(n)
 */
vector<int> countBits(int num) {
    vector<int> result = {0};
    for (int i = 1; i <= num; ++i)
        result.push_back(result[i & (i - 1)] + 1);
    return result;
}

int main() {
    for (auto iter : countBits(2))
        std::cout << iter << ' ';
    return 0;
}
```

```c++
#include <iostream>
#include <vector>
using namespace std;

/*
 * i的1的位数为i>>1的1的位数加上i&1(如果最低位为1，即i>>1的1的位数加1，如果最低位为0，
 * 即i>>1的1的位数。本质上i&1是判断i是否为奇数，如果是，则result[i]=result[i>>2]+1，
 * 否则，result[i] = result[i>>2]
 */
vector<int> countBits(int num) {
    vector<int> result(num+1, 0);
    for (int i = 1; i <= num; ++i)
        result[i] = result[i>>1] + (i&1);
    return result;
}

int main() {
    for (auto iter : countBits(11))
        std::cout << iter << ' ';
    return 0;
}
```

## 394-Decode String

> 给定一个经过编码的字符串，返回它解码后的字符串。
>
> 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
>
> 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
>
> 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
>
> 示例：
>
> ```
> s = "3[a]2[bc]", 返回 "aaabcbc".
> s = "3[a2[c]]", 返回 "accaccacc".
> s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
> ```

```c++

```

