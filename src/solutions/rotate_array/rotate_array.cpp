/**
 * Rotate Array
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
 * [5,6,7,1,2,3,4].
 *
 * Note: Try to come up as many solutions as you can, there are at least 3
 * different ways to solve this problem.
 *
 * Hint: Could you do it in-place with O(1) extra space?
 *
 * Credits: Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 *
 * Tags: Array
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
    void rotate(int nums[], int n, int k) {
        for (int i = 0; i < k%n; ++i)
            shift_right(nums, n);
    }

    void shift_right(int nums[], int n) {
        int temp = nums[n-1];
        for (int i = n-2; i >= 0; --i)
            nums[i+1] = nums[i];
        nums[0] = temp;
    }

    void rotate2(int nums[], int n, int k) {
        k %= n;
        reverse(nums, nums + n);
        reverse(nums, nums + k);
        reverse(nums + k, nums + n);
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int k;
        iss >> k;
        vector<int> nums((istream_iterator<int>(iss)), istream_iterator<int>());
        Solution().rotate2(&nums[0], nums.size(), k);
        copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}
