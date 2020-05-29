# 需要复习的题

1. [addTwoNumbers](#2-Add-Two-Numbers)
2. [countBits](#338-Counting-Bits)
3. [decodeString](#394-Decode-String)

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

```c++
//
// Created by wangheng on 2020/5/27.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1{
public:
    // 暴力解法，时间复杂度为O(n*sizeof(int))，空间复杂度为O(n)
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
};

class Solution2{
public:
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
};

class Solution3{
public:
    /*
     * i的1的位数为i>>1的1的位数加上i&1(如果最低位为1，即i>>1的1的位数加1，如果最低位为0，
     * 即i>>1的1的位数。
     */
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        for (int i = 1; i <= num; ++i)
            result[i] = result[i>>1] + (i&1);
        return result;
    }
};

int main() {
    Solution3 solution;
    for (auto iter : solution.countBits(11))
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
//
// Created by wangheng on 2020/5/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using std::string;
using std::vector;
using std::stoi;
using std::reverse;
using std::isdigit;
using std::isalpha;

/*
 * 使用栈操作解题，当遇到数字和左括号'['时进栈，若遇到有括号']'，则开始出栈直至出栈遇到左括号'['，
 * 左括号'['出栈之后，栈顶元素一定是当前sub对应的字符串出现的次数，将得到的重复n次的字符串后重新
 * 压入栈，重复上述操作直至到达字符串结尾。
 */
class Solution1{
public:
    string getDigits(string& s, size_t &ptr) {
        string ret = "";
        // 如果多个数字连续出现，可以一次读取连续数字段
        while (isdigit(s[ptr]))
            ret.push_back(s[ptr++]);
        return ret;
    }

    string getString(vector<string> &v) {
        string ret;
        for (const string& iter : v)
            ret += iter;
        return ret;
    }
    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if(isalpha(cur) || cur == '[') {
                // 获取一个字母进栈
                stk.push_back(string(1, s[ptr++]));
            } else {
                ++ptr;
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                // 将出栈的字母倒序
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前sub对应的字符串应该出现的次数
                int times = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                while (times--)
                    t += o;
                // 将构造好的字符串进栈
                stk.push_back(t);
            }
        }
        return getString(stk);
    }
};

/*
 * 递归解法，采用分治的思想，解析外层括号之前，先解析内层括号。
 * 假如该字符串中存在左括号“[”,当碰到左括号"["时，重复上一步骤；
 * 假如该字符串中不存在“[”了，那么下一个碰到的一定是右括号“]”,
 * 当碰到右括号“]”,说明以上一个左括号“[”开头的字符到此结束，
 * 只需要记录该字符串然后再乘以“[”前的数字即可。
 */
class Solution2{
public:
    string analysis(string s, int& index) {
        string res;
        int num = 0;
        string temp;
        while (index < s.size()) {
            if (s[index] >= '0' && s[index] <= '9') {
                num = 10 * num + s[index] - '0';
            } else if (s[index] == '[') {
                temp = analysis(s, ++index);
                while (num--)
                    res += temp;
                num = 0;
            } else if (s[index] == ']')
                break;
            else
                res += s[index];
            ++index;
        }
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return analysis(s, index);
    }
};

int main() {
    Solution2 solution;
    std::cout << solution.decodeString("ef3[2[c4[p]10[bg]ef]3[mn]]") << std::endl;

    return 0;
}
```

