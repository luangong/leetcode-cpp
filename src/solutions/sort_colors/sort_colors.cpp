/*
 * Sort Colors
 *
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red,
 * white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white,
 * and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this problem.
 *
 * Follow up:
 *
 * A rather straightforward solution is a two-pass algorithm using counting sort.
 *
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
 * array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 *
 * Tags: Array, Two Pointers, Sort
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size()-1;
        while (j <= k) {
            if (nums[j] < 1)
                swap(nums[j++], nums[i++]);
            else if (nums[j] > 1)
                swap(nums[j], nums[k--]);
            else
                ++j;
        }
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> vec((istream_iterator<int>(iss)), istream_iterator<int>());
        Solution().sortColors(vec, vec.size());
        // for_each(vec.begin(), vec.end(), [](int elem){ cout << elem << ' '; });
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}
