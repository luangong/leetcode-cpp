/**
 * Search Insert Position
 *
 * Given a sorted array and a target value, return the index if the target is
 * found.  If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 *
 *    [1,3,5,6], 5 -> 2
 *    [1,3,5,6], 2 -> 1
 *    [1,3,5,6], 7 -> 4
 *    [1,3,5,6], 0 -> 0
 *
 * Tags: Array, Binary Search
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // 可以直接使用 STL 的 lower_bound 算法
        // return lower_bound(A, A + n, target) - A;
        int lower = 0, upper = n;
        while (lower < upper) {
            int middle = lower + (upper - lower) / 2;
            // 注意这里即使发现 A[middle] == target 也要右边界往左移，这样
            // 如果数组有重复，我们就可以找到等于 target 的最左边的元素
            if (A[middle] < target)
                lower = middle + 1;
            else
                upper = middle;
        }
        return lower;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int target;
        iss >> target;
        vector<int> A((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().searchInsert(&A[0], A.size(), target) << endl;
    }
    return 0;
}
