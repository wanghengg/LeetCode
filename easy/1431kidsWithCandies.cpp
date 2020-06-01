//
// Created by wangheng on 2020/6/1.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int size = candies.size();
        if (size == 0) return vector<bool>{false};
        int leastCandies = *max_element(candies.begin(), candies.end()) - extraCandies;
        vector<bool> result(size, false);
        for (int i = 0; i < size; ++i) {
            if (candies[i] >= leastCandies)
                result[i] = true;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candies{3};
    int extraCandies = 3;
    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);
    cout << boolalpha;
    for (auto iter : result)
        cout << iter << endl;

    return 0;
}