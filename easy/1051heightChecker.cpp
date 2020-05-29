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