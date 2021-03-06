## 1 [countFactor.cpp](./countFactor.cpp)

>输入两个正整数`l`和`r`（不大于`10e9`）；对于满足`l < x < r`的所有`x`，求`x`的所有约数，然后只计数**约数最高位的数码**出现次数；输出：1~9每个数码出现的次数。
>
>例：输入：
>`l = 1, r = 4`
>
>输出：
>
>```
>4
>2
>1
>1
>0
>0
>0
>0
>0
>```

```c++
#include <iostream>
using namespace std;

long long Ask(long long u, long long r) {
    long long x, y, ans = 0;
    for (long long i = 1; i <= r / u; i *= 10) {
        x = u * i;
        y = r < (x + i - 1) ? r : (x + i - 1);
        for (long long j = x, k; j <= y; j = k + 1) {
            k = y < (r / (r / j)) ? y : (r / (r / j));
            ans += (k - j + 1) * (r / j);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    long long l, r;
    std::cin >> l >> r;
    for (int i = 1; i <= 9; i++) {
        cout << i << ": " << Ask(i, r) - Ask(i, l-1) << endl;
    }

    return 0;
}
```

## 2 [groupAnagrams](./groupAnagrams.cpp)

> Given an array of strings, group anagrams together. For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
  Return:
  [
    ["ate", "eat","tea"],
    ["nat","tan"],
    ["bat"]
  ]

```c++
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

/*
 * 用hash map求解
 */
class Solution{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& data) {
        std::unordered_map<std::string, int> hash;
        std::vector<std::vector<std::string>> result;
        int value = 0;
        int len = data.size();
        for (int i = 0; i < len; ++i) {
            std::string temp = data[i];
            std::sort(temp.begin(), temp.end());    // 将每个string先排序
            if (hash.count(temp) == 0) {
                hash.insert({temp, value}); // 如果排序后的string还未存在，添加到hash中
                // 重新构造一个新的vector<string>插入
                result.push_back(std::vector<std::string>{data[i]});
                ++value;
            } else{
                result[hash[temp]].push_back(data[i]);
            }
        }
        return result;
    }
};

int main() {
    std::vector<std::string> data{"eat", "tea", "tan", "ate", "nat", "cod",
                                  "atb", "bat", "doc"};
    Solution solution;
    std::vector<std::vector<std::string>> result = solution.groupAnagrams(data);
    for (auto& line : result) {
        for (auto& iter : line)
            std::cout << iter << ' ';
        std::cout << std::endl;
    }

    return 0;
}
```