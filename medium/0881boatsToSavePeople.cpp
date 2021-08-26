//
// Created by wh969 on 2021/8/26.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size()-1;
        int res = 0;
        while (left < right) {
            if (people[right] + people[left] > limit) {
                right--;
                res++;
            }
            if (people[right] + people[left] <= limit) {
                right--;
                left++;
                res++;
            }
        }
        if (left == right) { res++; }
        return res;
    }
};