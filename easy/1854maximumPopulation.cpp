//
// Created by wh969 on 2021/7/24.
//

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

class Solution{
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {return a[0] <= b[0];});
        priority_queue<int, vector<int>, greater<int>> livingPeopleDeathTime;
        int counts = 0;
        int result = 0;
        int maxPopulation = 0;
        for (auto &log : logs) {
            while (!livingPeopleDeathTime.empty() && livingPeopleDeathTime.top() <= log[0]) {
                livingPeopleDeathTime.pop();
                --counts;
            }
            ++counts;
            livingPeopleDeathTime.push(log[1]);
            if (counts > maxPopulation) {
                result = log[0];
                maxPopulation = counts;
            }
        }
        return result;
    }
};

class Solution1{
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        const int offset = 1950;
        vector<int> delta(101, 0);  // 当前年份人口变化量
        for (auto &log : logs) {
            delta[log[0] - offset]++;
            delta[log[1] - offset]--;
        }
        int counts = 0;
        int curPopulation = 0;
        int year;
        for (int i = 0; i < 101; ++i) {
            counts += delta[i];
            if (counts > curPopulation) {
                curPopulation = counts;
                year = offset + i;
            }
        }
        return year;
    }
};