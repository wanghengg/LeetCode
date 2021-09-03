#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    float getScale(vector<int> point1, vector<int> point2) {
        return float(point2[1] - point1[1])  / (point2[0] - point1[0]);
    }
    int maxPoints(vector<vector<int>>& points) {
        map<float, unordered_set<vector<int>>> m;
        for (int i = 0; i < points.size()-1; ++i) {
            float scale = getScale(points[i], points[i+1]);
            if (m.count(scale) == 0) {
                m[scale] = set<vector<int>>();
            }
            m[scale].insert(points[i]);
            m[scale].insert(points[i+1]);
            for (int j = i+2; j < points.size(); ++j) {
                float newScale = getScale(points[i], points[j]);
                if (m.count(newScale) == 0) {
                    m[newScale] = set<vector<int>>();
                }
                m[newScale].insert(points[j]);
            }
        }
        return m.end()->second.size();
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points{{1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4}};
    cout << solution.maxPoints(points) << endl;
    map<int, set<int>> m;
    m[1].insert(3);
    cout << m[1].size() << endl;
    return 0;
}