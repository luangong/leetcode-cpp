/**
 * Find Minimum in Rotated Sorted Array II
 *
 * Follow up for "Find Minimum in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity?  How and why?
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., [0 1 2 4 5 6 7] might become [4 5 6 7 0 1 2]).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
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
    int findMin(vector<int> &num) {
        int lower = 0, upper = num.size()-1;
        while (lower < upper && num[lower] >= num[upper]) {
            int middle = (lower + upper) / 2;
            if (num[middle] > num[upper])
                lower = middle + 1;
            else if (num[middle] < num[lower])
                upper = middle;
            else
                ++lower;
        }
        return num[lower];
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
