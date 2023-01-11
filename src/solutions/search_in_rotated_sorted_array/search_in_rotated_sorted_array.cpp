/**
 * Search in Rotated Sorted Array
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search.  If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Tags: Array, Binary Search
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int lower = 0;
        int upper = n-1;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[mid] >= A[lower])
                if (A[lower] <= target && target < A[mid])
                    upper = mid - 1;
                else
                    lower = mid + 1;
            else
                if (A[mid] < target && target <= A[upper])
                    lower = mid + 1;
                else
                    upper = mid - 1;
        }
        return -1;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int target;
        iss >> target;
        vector<int> A((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().search(&A[0], A.size(), target) << endl;
    }
    return 0;
}
