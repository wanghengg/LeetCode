//
// Created by wh969 on 2021/4/8.
//

#include <bits/stdc++.h>
using namespace std;

/*
 * 用大根堆保存较小的部分，小根堆保存较大的部分，元素总数N为奇数时，小根堆多保存一个元素，N为偶数时，二者保存同样的元素数量
 *
 * 有新元素插入时，如果大根堆和小根堆的元素个数相等，则将元素先插入大根堆，然后将大根堆的top元素（最大值）弹出并插入小根堆，
 * 这样保证了大根堆里面保存较小部分的元素，小根堆里面保存较大部分的元素
 *
 * 如果新元素插入时大根堆和小根堆的元素个数不相等，根据前面的分析肯定是小根堆的元素多一个，所以应该保证大根堆的元素+1，具体操作为
 * 将新元素插入小根堆，然后将小根堆的top元素（最小值）弹出并插入大根堆，这样也是为了保证大根堆里面保存较小部分的元素，小根堆里面
 * 保存较大部分的元素（假设新插入的元素大于小根堆中的部分元素，如果直接插入大根堆，那么不能保证大根堆里面的所有元素小于小根堆的所有
 * 元素，这样找到的中位数肯定错误，所以应该把新插入元素放入小根堆，经过优先级队列的自动调整后，小根堆的堆顶是小根堆中最小的元素，然后
 * 将其弹出插入大根堆，这样就保证了大根堆里面的所有元素小于小根堆的所有元素，同时将大根堆的元素数量+1，保证大根堆和小根堆的元素数量
 * 相等。
 */
class MedianFinder{
public:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) * 0.5;
        } else {
            return minHeap.top();   // 根据之前的设计，如果元素总数为奇数，那么小根堆的元素比大根堆多一个
        }
    }
};