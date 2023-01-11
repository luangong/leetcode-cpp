/**
 * Search for a Range
 *
 * Given a sorted array of integers, find the starting and ending position of a
 * given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example, given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
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
    vector<int> searchRange2(int A[], int n, int target) {
        auto range = equal_range(A, A+n, target);
        if (range.first == range.second)
            return vector<int>{-1, -1};
        else
            return vector<int>{int(range.first-A), int(range.second-A-1)};
    }

    vector<int> searchRange(int A[], int n, int target) {
        int lower = lower_bound(A, n, target);
        int upper = upper_bound(A, n, target);
        if (lower < upper)
            return vector<int>{lower, upper-1};
        else
            return vector<int>{-1, -1};
    }

    /**
     * Return the smallest index in A that equals target, or the position
     * to be inserted before if target is not found.
     */
    int lower_bound(int A[], int n, int target) {
        int lower = 0, upper = n;
        while (lower < upper) {
            int middle = lower + (upper - lower) / 2;
            if (A[middle] < target)
                lower = middle + 1;
            else
                upper = middle;
        }
        return lower;
    }

    /**
     * Return one past the largest index in A that equals target, or the position
     * to be inserted before if target is not found.
     */
    int upper_bound(int A[], int n, int target) {
        int lower = 0, upper = n;
        while (lower < upper) {
            int middle = lower + (upper - lower) / 2;
            if (A[middle] <= target)
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
        auto range = Solution().searchRange(&A[0], A.size(), target);
        cout << range[0] << " " << range[1] << endl;
    }
    return 0;
}
