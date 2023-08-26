/**
 * Search in Rotated Array II
 *
 * Follow up for "Search in Rotated Sorted Array": What if duplicates are
 * allowed?  Would this affect the run-time complexity?  How and why?
 *
 * Write a function to determine if a given target is in the array.
 *
 * Tags: Array, Binary Search
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        return find(A, A+n, target) != A+n;
    }

    // Worst-case time complexity is O(n)
    bool search(int A[], int n, int target) {
        int lower = 0, upper = n-1;
        while (lower <= upper) {
            int mid = lower + (upper - lower) / 2;
            if (A[mid] == target)
                return true;
            if (A[lower] < A[mid])
                if (A[lower] <= target && target < A[mid])
                    upper = mid;
                else
                    lower = mid + 1;
            else if (A[lower] > A[mid])
                if (A[mid] < target && target <= A[upper])
                    lower = mid + 1;
                else
                    upper = mid;
            else
                ++lower;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    return 0;
}
