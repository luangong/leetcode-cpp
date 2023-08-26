/*
 * Bitwise AND of Numbers Range
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 *
 * For example, given the range [5, 7], you should return 4.
 *
 * Credits: Special thanks to @amrsaqr for adding this problem and creating all
 * test cases.
 *
 * Tags: Bit Manipulation
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};

int main(int argc, char **argv) {
    int m, n;
    while (cin >> m >> n)
        cout << Solution().rangeBitwiseAnd(m, n) << endl;
    return 0;
}
