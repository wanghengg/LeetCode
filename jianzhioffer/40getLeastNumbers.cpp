#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res(k, 0);
        for (int i = 0; i < k; ++i) {
            res[i] = arr[i];
        }
        return res;
    }
};

class Solution1 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if (k == 0) return res;
        priority_queue<int> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(arr[i]);
        }

        for (int i = k; i < arr.size(); ++i) {
            if (q.top() > arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
        }

        for (int i = 0; i < k; ++i) {
            res[i] = q.top();
            q.pop();
        }
        return res;
    }
};