/**
 * Single Number II
 *
 * Given an array of integers, every element appears three times except for one.
 * Find that single one.
 *
 * Note: Your algorithm should have a linear runtime complexity.  Could you
 * implement it without using extra memory?
 *
 * Tags: Bit Manipulation
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Method 1: Use a map to count each number
    int singleNumber(int A[], int n) {
        map<int, int> count;
        for (int i = 0; i < n; ++i)
            ++count[A[i]];
        for (auto p: count)
            if (p.second == 1)
                return p.first;
        return 0;
    }

    // Method 2: Bit manipulation
    int singleNumber2(int A[], int n) {
        int result = 0;
        for (int i = 0; i < numeric_limits<int>::digits + 1; ++i) {
            // Count number of 1's on i-th bit for all the elements
            int num_ones = 0;
            for (int j = 0; j < n; ++j)
                num_ones += (A[j] >> i) & 1;
            if (num_ones % 3 != 0)
                result |= (1 << i);
            // result |= (count % 3) << i;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> vec((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().singleNumber2(&vec[0], vec.size()) << endl;
    }
    return 0;
}
