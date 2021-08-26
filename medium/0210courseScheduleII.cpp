//
// Created by wh969 on 2021/8/26.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> inDegree;
    // 存储答案
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        inDegree.resize(numCourses);
        for(const auto& info : prerequisites) {
            edges[info[1]].emplace_back(info[0]);
            ++inDegree[info[0]];
        }
        queue<int> q;
        // 将所有入度为0的节点放入队列中
        for(int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            // 从队首取出一个节点
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(int v : edges[u]) {
                --inDegree[v];
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (result.size() != numCourses) {
            return {};
        }
        return result;
    }
};