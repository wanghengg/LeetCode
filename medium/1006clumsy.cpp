#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int help(int N) {
        if (N == 1) return -1;
        if (N == 2) return -2;
        if (N == 3) return -6;
        if (N == 4) return -5;
        return (-N) * (N-1) / (N-2) + (N-3) + help(N-4);
    }
    int clumsy(int N) {
        if (N > 4) {
            return help(N) + 2 * (N * (N-1) / (N-2));
        } else if (N == 4) {
            return 7;
        } else if (N == 3) {
            return 6;
        } else if (N == 2) {
            return 2;
        } else {
            return 1;
        }
    }
};