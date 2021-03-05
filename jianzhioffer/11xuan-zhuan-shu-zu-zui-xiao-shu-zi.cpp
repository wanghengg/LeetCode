#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Solution{
public:
    int minArray(vector<int>& numbers) {
        if (numbers.empty()) return -1;
        if (numbers.size() == 1) return numbers[0];
        int first = 0, second = 1;
        int length = numbers.size();
        while (second < length) {
            if (numbers[first] > numbers[second])
                return numbers[second];
            first++;
            second++;
        }
        return numbers[0];
    }

    // 此题涉及到查找算法，同时数组有序，所以可以使用二分查找
    int minArray1(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (numbers[mid] < numbers[right]) {
                right = mid;
            } else if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else {
                right--;
            }
        }
        return numbers[left];
    }
};