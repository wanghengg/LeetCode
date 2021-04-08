//
// Created by wangheng on 2021/4/8.
//

#include <bits/stdc++.h>
using namespace std;

// 没有必要把所有的数据进行排序，只需要保证数据左半边的数都小于右半边的数，那么根据左半边的最大值和右半边的最小值即可得到中位数
class MedianFinder{
public:
    // 保证两个堆的元素数量之差不超过1
    priority_queue<int, vector<int>, less<int>> maxHeap;  // 大根堆，所有元素中小的一半
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小根堆，所有元素中大的一半
    MedianFinder() {}

    void addNum(int num) {
        // 如果大根堆和小根堆的元素个数相等，先把新插入的元素插入大根堆，保证大根堆的元素有序，然后将大根堆的top元素弹出压入小根堆，
        // 结果小根堆的元素比大根堆多一个，此时中位数即为小根堆的top元素
        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            // 如果大根堆和小根堆元素的个数不一样，由上面的分析可知肯定是小根堆的元素比大根堆的元素多，将元素插入小根堆排序后，将小根堆的top元素
            // 插入大根堆
            minHeap.push(num);  // 插入小根堆
            maxHeap.push(minHeap.top());    // 将小根堆的top即最小值插入大根堆
            minHeap.pop();
        }
    }

    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        } else {
            return minHeap.top();
        }
    }
};