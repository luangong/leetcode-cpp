/**
 * Find Minimum in Rotated Sorted Array
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., [0 1 2 4 5 6 7] might become [4 5 6 7 0 1 2]).
 *
 * Find the minimum element.
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
    int findMin(vector<int>& num) {
        int lower = 0, upper = num.size();
        while (lower < upper) {
            int middle = lower + (upper - lower) / 2;
            // Always compare with the first element of the original array
            if (num[middle] >= num[0])
                lower = middle + 1;
            else
                upper = middle;
        }

        // If the whole array is increasing, then lower == num.size(),
        // so we should return num[0] as the smallest element
        return num[lower%num.size()];
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> numbers((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().findMin(numbers) << endl;
    }
    return 0;
}
