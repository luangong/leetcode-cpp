#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class MedianFinder {
public:
    void append(int value);
    double findMedian();
private:
    /*
     *  1  2  3  4  5  6
     *
     *     3        4
     *   /   \    /   \
     *  1     2  5     6
     */
    // 大顶堆，维护较小的一半元素，堆顶为较小的一半元素中的最大值
    priority_queue<int> smallerHeap;

    // 小顶堆，维护较大的一半元素，堆顶为较大的一半元素中的最小值
    priority_queue<int, vector<int>, greater<int>> largerHeap;
};

void MedianFinder::append(int value) {
    // Put the new element into the appropriate heap
    if (smallerHeap.empty() && largerHeap.empty()) {
        smallerHeap.push(value);
        return;
    }

    if (value < smallerHeap.top()) {
        smallerHeap.push(value);
        // Balance the two heaps, if necessary
        if (smallerHeap.size() - largerHeap.size() >= 2) {
            largerHeap.push(smallerHeap.top());
            smallerHeap.pop();
        }
    } else {
        largerHeap.push(value);
        // Balance the two heaps, if necessary
        if (largerHeap.size() - smallerHeap.size() >= 2) {
            smallerHeap.push(largerHeap.top());
            largerHeap.pop();
        }
    }
}

double MedianFinder::findMedian() {
    if (smallerHeap.size() < largerHeap.size())
        return largerHeap.top();
    else if (smallerHeap.size() > largerHeap.size())
        return smallerHeap.top();
    else
        return (smallerHeap.top() + largerHeap.top()) / 2.0;
}

int main(int argc, char **argv) {
    MedianFinder finder;
    int sum = 0;
    int value;
    while (cin >> value) {
        finder.append(value);
        sum += finder.findMedian();
    }
    cout << sum % 10000 << endl;
    return 0;
}
