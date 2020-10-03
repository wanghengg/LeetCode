#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int res = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            res = (res > height[left] * (right - left)) ? res : height[left] * (right - left);
            left++;
        }
        else {
            res = (res > height[right] * (right - left)) ? res : height[right] * (right - left);
            right--;
        }
    }
    return res;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;

    return 0;
}