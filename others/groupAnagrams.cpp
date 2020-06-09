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
