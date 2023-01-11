/**
 * 有一堆数，除了两个数各出现一次（或奇数次）以外，其他数字都出现了两次（或偶数
 * 次），要求找出这两个数分别是多少
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Compute a XOR b
        int a_xor_b = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Find the first 1 from right to left
        int first_one = 1;
        while ((a_xor_b & first_one) == 0)
            first_one <<= 1;
        // Construct a and b
        int a = 0, b = 0;
        for (int x : nums)
            if (x & first_one)
                a ^= x;
            else
                b ^= x;
        return { a, b };
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> nums((istream_iterator<int>(iss)), istream_iterator<int>());
        auto ab = Solution().singleNumber(nums);
        cout << ab[0] << ' ' << ab[1] << endl;
    }
    return 0;
}
