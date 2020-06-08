# 需要复习的题

1. [addTwoNumbers](#2-Add-Two-Numbers)
2. [longestPalindromeSubstring](#5-Longest-Palindrome-Substring)
3. [countBits](#338-Counting-Bits)
4. [decodeString](#394-Decode-String)
5. [productOfArrayExceptItself](#238-Product-Of-Array-Except-Itself)
6. [spiralMatrix](#54-Spiral-Matrix)
7. [threeSum](#15-Three-Sum)
8. [longestSubstringWithoutRepeatingCharacters](#3-Longest-Substring-Without-Repeating-Characters)

## 2-Add Two Numbers

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

```c++
//
// Created by wangheng on 2020/5/27.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 时间复杂度为O(n)，空间复杂度为O(1)，只进行一次扫描
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0;
        int sum;
        while (head1->next != nullptr && head2->next != nullptr) {
            // 最终返回l1,用l1表示结果
            sum = head1->val + head2->val + carry;
            if (sum > 9) {
                head1->val = sum % 10;
                carry = 1;
            } else {
                head1->val = sum;
                carry = 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // 如果l1比l2短，用head1->next = head2->next将l2长出来的部分接在l1之后
        if (head1->next == nullptr && head2->next != nullptr) {
            head1->next = head2->next;
            sum = head1->val + head2->val + carry;
            if (sum > 9) {
                head1->val = sum % 10;
                carry = 1;
            } else {
                head1->val = sum;
                carry = 0;
            }
            while (head1->next != nullptr) {
                head1 = head1->next;
                if ((head1->val + carry) > 9) {
                    head1->val = 0;
                    carry = 1;
                } else {
                    head1->val = head1->val + carry;
                    carry = 0;
                    // 在长出来的部分，如果某一位不进位，那么其后的每一位都不会进位，所以break
                    break;
                }
            }
            // 如果所有的加法做完之后，carry=1，说明最末位进位，需要增加一个节点，使其值为1，
            // 连接在末节点之后
            if (carry == 1)
                head1->next = new ListNode(carry);
            return l1;
        }

        if (head1->next != nullptr && head2->next == nullptr) {
            sum = head1->val + head2->val + carry;
            if (sum > 9) {
                head1->val = sum % 10;
                carry = 1;
            } else {
                head1->val = sum;
                carry = 0;
            }
            while (head1->next != nullptr) {
                head1 = head1->next;
                if ((head1->val + carry) > 9) {
                    head1->val = 0;
                    carry = 1;
                } else {
                    head1->val = head1->val + carry;
                    carry = 0;
                    break;
                }
            }
            if (carry == 1)
                head1->next = new ListNode(carry);
            return l1;
        }

        if (head1->next == nullptr && head2->next == nullptr) {
            sum = head1->val + head2->val + carry;
            if (sum > 9) {
                head1->val = sum % 10;
                carry = 1;
            } else {
                head1->val = sum;
                carry = 0;
            }
            if (carry == 1)
                head1->next = new ListNode(carry);
            return l1;
        }
        return l1;
    }
};

int main() {
    Solution solution;
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(8);
    ListNode* l2 = new ListNode(1);
    ListNode* result = solution.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        std::cout << result->val << ' ';
        result = result->next;
    }

    return 0;
}
```



## 3-Longest Substring Without Repeating Characters

> 给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。
>
> **示例 1:**
>
> ```
> 输入: "abcabcbb"
> 输出: 3 
> 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
> ```
>
> **示例2：**
>
> ```
> 输入: "bbbbb"
> 输出: 1
> 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
> ```
>
> **示例3：**
>
> ```
> 输入: "pwwkew"
> 输出: 3
> 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
>      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
> ```

```c++
//
// Created by wangheng on 2020/6/1.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

// 使用双指针
class Solution1{
public:
    int lengthOfLongestSubstring(string s) {
        auto first = s.begin();
        auto second = first + 1;
        int res = 0;
        while (first != s.end()) {
            while (second != s.end() && find(first, second, *second) == second)
                ++second;
            res = (second - first > res) ? (int)(second - first) : res;
            ++first;
        }
        return res;
    }
};

// 滑动窗口
class Solution2{
public:
    int lengthOfLongestSubstring(string s) {
        // hash集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

int main() {
    string s{"pwwkew"};
    Solution2 solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
```



## 5-Longest Palindrome Substring

> 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
>
> 示例1：
>
> ```
> 输入: "babad"
> 输出: "bab"
> 注意: "aba" 也是一个有效答案。
> ```
>
> 示例2：
>
> ```
> 输入: "cbbd"
> 输出: "bb"
> ```

**动态规划**

对于一个子串而言，如果它是回文串，并且长度大于 22，那么将它首尾的两个字母去除之后，它仍然是个回文串。例如对于字符串 “ababa”，如果我们已经知道”bab”是回文串，那么“ababa” 一定是回文串，这是因为它的首尾两个字母都是“a”。

根据这样的思路，可以使用动态规划的方法解决本题。我们用$P(i,j)$表示字符串$s$的第$i$到$j$个字母组成的串($s[i:j]$)是否为回文串：

$$P(i,j) = \begin{cases}true & 如果子串s[i:j]是回文串 \\ false & 其他情况 \end{cases}$$

这里的其他情况包含两种可能性:

* $s[i:j]$本身就不是回文串；
* $i > j$，此时$s[i:j]$本身不合法。

那么我们就可以写出动态规划状态转移方程：

$$P(i,j) = P(i+1, j-1) \wedge (S_i == S_j)$$

也就是说，只有$s[i+1, j-1]$是回文串，并且$s$的第$i$和$j$个字母相同时，$s[i:j]$才会是回文串。

上文的所有讨论是建立在子串长度大于 2 的前提之上的，我们还需要考虑动态规划中的边界条件，即子串的长度为 1或 2。对于长度为 1 的子串，它显然是个回文串；对于长度为 2 的子串，只要它的两个字母相同，它就是一个回文串。因此我们就可以写出动态规划的边界条件：

$$\begin{cases}P(i,i)=true \\ P(i,i+1)=(S_i == S_{i+1})\end{cases}$$

根据这个思路，就可以完成动态规划了，最终的答案为所有$P(i, j)=true$中$j-i+1$（即子字符串长度）的最大值。**注意：在状态转移方程中，我们是从长度较短的字符串向长度较长的字符串的字符串进行转移的，因此一定要注意动态规划的循环顺序。**

```c++
//
// Created by wangheng on 2020/5/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 暴力解法，时间复杂度O(n^3)
class Solution1{
public:
    string longestPalindrome(string s) {
        int length = s.size();
        string result;
        for (int i = 0; i < length; ++i) {
            for (int j = i; j < length; ++j) {
                string temp = string(s, i, j - i + 1);
                if (isPalindrome(temp) && result.size() < temp.size())
                    result = temp;
            }
        }
        return result;
    }

    bool isPalindrome(string& s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        return s == temp;
    }
};


// 动态规划方法
class Solution2{
public:
    string longestPalindrome(string s) {
        int length = s.size();
        vector<vector<int>> dp(length, vector<int>(length));
        string result;
        for (int l = 0; l < length; ++l) {
            for (int i = 0; i + l < length; ++i) {
                int j = i + l;
                if (l == 0)
                    dp[i][j] = 1;
                else if (l == 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if (dp[i][j] && result.size() < l + 1)
                    result = s.substr(i, l + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution2 solution;
    cout << solution.longestPalindrome("eacaeb") << endl;
    string str1 = "hello";

    return 0;
}
```



## 15-Three Sum

> 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
>
> 注意：答案中不可以包含重复的三元组。
>
> 示例：
>
> ```
> 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
> 
> 满足要求的三元组集合为：
> [
>   [-1, 0, 1],
>   [-1, -1, 2]
> ]
> ```

```c++
//
// Created by wangheng on 2020/6/8.
//

#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 双指针法
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return {};
        // 将nums排序，对排序数组查找两个数之和等于-nums[i]，时间复杂度为O(n)
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < len - 2; ++i) {
            // 如果第一个数大于0，-nums[i]小于0，由于是有序数组，后面的数全都大于零，
            // 所以不存在两数之和等于负数
            if (nums[i] > 0) break;
            if (i == 0 || nums[i] != nums[i-1]) {
                int j = i + 1, k = len - 1; // 双指针
                while (j < k) {
                    // 当两数之和小于结果时，由于数组时有序的，所以++j，第一个指针右移
                    if (nums[j] + nums[k] < -nums[i]) {
                        ++j;
                        while (j < k && nums[j] == nums[j-1]) ++j;
                    }
                    else if (nums[j] + nums[k] == -nums[i]) {
                        result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                        --k;
                        ++j;
                        // 得到一个结果之后，右移第一个指针直到指向不同的数字，
                        // 左移第二个指针直到指向不同的数字，避免重复的结果
                        while (j < k && nums[j] == nums[j-1]) ++j;
                        while (j < k && nums[k] == nums[k+1]) --k;
                    } else {
                        --k;
                        while (j < k && nums[k] == nums[k+1]) --k;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4, 0, 1};
    Solution solution;
    auto result = solution.threeSum(nums);
    for (auto& vec : result) {
        for (auto &i : vec)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}
```

## 54-Spiral Matrix

> 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
>
> 示例1：
>
> ```
> 输入:
> [
>  [ 1, 2, 3 ],
>  [ 4, 5, 6 ],
>  [ 7, 8, 9 ]
> ]
> 输出: [1,2,3,6,9,8,7,4,5]
> ```
>
> 示例2：
>
> ```
> 输入:
> [
>   [1, 2, 3, 4],
>   [5, 6, 7, 8],
>   [9,10,11,12]
> ]
> 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
> ```

**方法一：模拟**

可以模拟打印矩阵的路径。初始位置是矩阵的左上角，初始方向是向右，当路径超出界限或者进入之前访问过的位置时，则顺时针旋转，进入下一个方向。

判断路径是否进入之前访问过的位置需要使用一个与输入矩阵大小相同的辅助矩阵 \textit{visited}visited，其中的每个元素表示该位置是否被访问过。当一个元素被访问时，将 visited 中的对应位置的元素设为已访问。

如何判断路径是否结束？由于矩阵中的每个元素都被访问一次，因此路径的长度即为矩阵中的元素数量，当路径的长度达到矩阵中的元素数量时即为完整路径，将该路径返回。

```c++
class Solution1{
private:
    static int directions[4][2];
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int total = rows * columns;
        vector<int> result(total);

        int row = 0, column = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; ++i) {
            result[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn])
                directionIndex = (directionIndex + 1) % 4;
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return result;
    }
};

int Solution1::directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
```

**复杂度分析**

* 时间复杂度：$O(mn)$，其中$m$和$n$分别是输入矩阵的行数和列数，矩阵中的每个元素都要被访问一次。
* 空间复杂度：$O(mn)$，需要创建一个大小为m x n 的矩阵$visited$记录每个位置是否被访问过。

**方法二： 按层模拟**

可以将矩阵看成若干层，首先打印最外层的元素，其次打印次外层的元素，直到打印最内层的元素。

定义矩阵的第 k 层是到最近边界距离为 kk 的所有顶点。例如，下图矩阵最外层元素都是第 1 层，次外层元素都是第 2 层，剩下的元素都是第 3 层。

```
[[1, 1, 1, 1, 1, 1, 1],
 [1, 2, 2, 2, 2, 2, 1],
 [1, 2, 3, 3, 3, 2, 1],
 [1, 2, 2, 2, 2, 2, 1],
 [1, 1, 1, 1, 1, 1, 1]]
```

对于每层，从左上方开始以顺时针的顺序遍历所有元素。假设当前层的左上角位于$(top, left)$，右下角位于 $(bottom, right)$，按照如下顺序遍历当前层的元素。

1. 从左到右遍历上侧元素，依次为$(top, left)$到 $(top, right)$。
2. 从上到下遍历元素，依次为$(top + 1, right)$到$(bottom, right)$。
3. 如果$left < right$且$top < bottom$，则从右到左遍历下侧元素，依次为$(bottom, right-1)$到$(bottom, left + 1)$，以及从下到上遍历左侧元素，依次为$(bottom, left)$到$(top + 1, left)$。

遍历完当前层元素之后，将$left$和$top$分别增加1，将$right$和$bottom$分别减少1，进入下一层继续遍历，直到遍历完所有元素为止。

![jianzhi_29_fig1](https://gitee.com/wanghengg/picture/raw/master/img/jianzhi_29_fig1.png)

```c++
class Solution2{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> result;

        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;

        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; ++column)
                result.push_back(matrix[top][column]);
            for (int row = top + 1; row <= bottom; ++row)
                result.push_back(matrix[row][right]);
            // 如果当前层只有一行或者只有，那么不需要下面的循环，否则会重复
            if (left < right && top < bottom) {
                for (int column = right - 1; column >= left; --column)
                    result.push_back(matrix[bottom][column]);
                for (int row = bottom - 1; row > top; --row)
                    result.push_back(matrix[row][left]);
            }
            ++left;
            ++top;
            --right;
            --bottom;
        }
        return result;
    }
};
```



## 238-Product Of Array Except Itself

> 给你一个长度为 $n$的整数数组 $nums$，其中 $n > 1$，返回输出数组 $output$ ，其中 $output[i]$ 等于$nums$ 中除 $nums[i]$ 之外其余各元素的乘积。
>
> 示例：
>
> ```
> 输入: [1,2,3,4]
> 输出: [24,12,8,6]
> ```
>
> 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
>
> 说明: **请不要使用除法**，且在$O(n)$ 时间复杂度内完成此题。
>
> 进阶：
> 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组**不被视为**额外空间。）

```c++
//
// Created by wangheng on 2020/6/4.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 左右列表乘积，用索引左侧所有数字的乘积和右侧所有数字的乘积(即前缀与后缀)相乘得到答案。
 * 初始化两个数组left和right，对于给定索引i，left[i]表示i左侧所有数字的乘积，right[i]
 * 表示i右侧所有数字的乘积，对于数组left和right，left[0]和right[nums.size()-1]应该
 * 为0，因为第一个元素左侧没有元素，所以左侧乘积为1，同理，最后一个元素右侧没有元素，所以
 * 右侧乘积应该为1.
 * left[i] = left[i-1] * nums[i-1]
 * right[i] = right[i+1] * nums[i+1]
 */
class Solution1{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        vector<int> left(size, 1);
        vector<int> right(size, 1);
        for (int i = 1; i < size; ++i) {
            left[i] = left[i-1] * nums[i-1];
            right[size-i-1] = right[size-i] * nums[size-i];
        }
        for (int i = 0; i < size; ++i)
            result[i] = left[i] * right[i];
        return result;
    }
};

/*
 * Solution1中result数组只在计算结果的时候使用，为了节省空间，可以使用result当做left使用，
 * 然后计算出索引i之前的所有元素之和，用一个整数right代替数组right[]，通过迭代的方法计算出
 * 每步i之后的所有元素之积。
 */
class Solution2{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        for(int i = 1; i < size; ++i)
            result[i] = result[i-1] * nums[i-1];
        int right = 1;
        for (int i = size-1; i >= 0; --i) {
            result[i] = result[i] * right;
            right *= nums[i];
        }
        return result;
    }
};

int main() {
    vector<int> nums{1,2,3,4,5};
    Solution2 solution;
    vector<int> result = solution.productExceptSelf(nums);
    for (auto &iter : result)
        cout << iter << ' ';
    return 0;
}
```



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

