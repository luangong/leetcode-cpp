/**
 * Largest Rectangle in Histogram
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 *
 * Above is a histogram where width of each bar is 1, given
 * height = [2,1,5,6,2,3].
 *
 * The largest rectangle is shown in the shaded area, which has area of 10 unit.
 *
 * For example, given height = [2,1,5,6,2,3], return 10.
 *
 * Tags: Array, Stack
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
    int largestRectangleArea(vector<int> &height) {
        int max_area = 0;
        return max_area;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> heights((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().largestRectangleArea(heights) << endl;
    }
    return 0;
}
