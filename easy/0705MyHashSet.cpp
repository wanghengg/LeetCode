#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class MyHashSet{
private:
    vector<list<int>> data;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }
public:
    MyHashSet() : data(base) {} // 给哈希表分配空间
    void add(int key) {
        int h = hash(key);
        for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
            if (*iter == key)
                return;
        }
        data[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        auto position = find(data[h].begin(), data[h].end(), key);
        if (position == data[h].end()) return;
        data[h].erase(position);
    }

    bool contains(int key) {
        int h = hash(key);
        for (auto& iter : data[h]) {
            if (iter == key)
                return true;
        }
        return false;
    }
};