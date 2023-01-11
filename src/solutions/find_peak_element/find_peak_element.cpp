/*
 * Find Peak Element
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return
 * its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function
 * should return the index number 2.
 *
 * Note: Your solution should be in logarithmic complexity.
 *
 * Credits: Special thanks to @ts for adding this problem and creating all test
 * cases.
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
    int findPeakElement(const vector<int> &num) {
        int lower = 0, upper = num.size()-1;
        while (lower < upper) {
            int mid = (lower + upper) / 2;
            if (num[mid] < num[mid+1])
                lower = mid + 1;
            else
                upper = mid;
        }
        return lower;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> nums((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().findPeakElement(nums) << endl;
    }
    return 0;
}
