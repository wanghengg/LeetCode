#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> index;   // 保存数出现的位置index
    vector<int> nums;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        // 如果val已经在nums里面，仍然将val插入nums最后，但是返回false,对于新插入元素val，
        // 在index里面保存其位置，因为插在nums末尾，所以index=nums.size()
        nums.push_back(val);
        index[val].insert(nums.size() - 1);
        return index[val].size() == 1;  // 如果原来不存在val，新插入val之后val出现次数为1，返回为true，如果val已经出现过，出现次数不等于1，返回false
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    /*
     * remove操作的重点在于删除时应该将最后一个元素复制到要删除元素第一次出现的位置，然后直接删除最后一个元素，只需要O(1)的时间
     * 如果直接在val第一次出现的位置删除val，由于vector在内存中连续存储，删除操作的时间复杂度为O(n)，不满足题目要求
     */
    bool remove(int val) {
        if (!index.count(val)) return false;
        // 判断val是否存在
        int i = *(index[val].begin());  // 如果存在，找到val在nums中的第一个位置
        nums[i] = nums.back();  // 要删除的元素时nums[i]，为了保证O(1)时间复杂度，将nums[i]等于最后一个数，相当于保留最后一个元素，然后删除最后一个数
        index[val].erase(i);    // 相应的val的位置也应该删掉
        index[nums[i]].erase(nums.size() - 1);  // 删除最后一个元素出现的位置
        // 如果val第一次出现的位置就是在nums的最后，则不用插入新的位置
        if (i < nums.size() - 1) {
            index[nums[i]].insert(i);
        }
        if (index[val].empty()) {   // 如果val被删除之后出现次数为0
            index.erase(val);
        }
        nums.pop_back();    // 从nums中删除最后一个元素，最后一个元素已经提前复制到位置i了，实际上删除的是nums[i]
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};