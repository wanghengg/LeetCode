#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution{
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occurNum;
        for (auto& it : arr) {
            occurNum[it]++;
        }
        set<int> uniqueTimes;
        for(auto& it : occurNum) {
            uniqueTimes.insert(it.second);
        }
        return occurNum.size() == uniqueTimes.size();
    }
};

int main() {
    vector<int> arr{1,2,2,1,1,3,3};
    Solution solution;
    cout << boolalpha << solution.uniqueOccurrences(arr) << endl;
    return 0;
}