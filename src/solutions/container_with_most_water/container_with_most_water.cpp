/**
 * Container with Most Water
 *
 * Given n non-negative integers a_1, a_2, ..., a_n, where each represents a
 * point at coordinate (i, a_i).  n vertical lines are drawn such that the two
 * endpoints of line i is at (i, a_i) and (i, 0).  Find two lines, which
 * together with x-axis forms a container, such that the container contains the
 * most water.
 *
 * Note: You may not slant the container.
 *
 * Tags: Array, Two Pointers
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
    int maxArea(const vector<int>& height) {
        int max_area = 0;
        int left = 0, right = height.size()-1;
        while (left < right) {
            int shorter = min(height[left], height[right]);
            int area = (right - left) * shorter;
            max_area = max(max_area, area);
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return max_area;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> heights((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().maxArea(heights) << endl;
    }
    return 0;
}
