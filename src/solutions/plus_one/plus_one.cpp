/**
 * Plus One
 *
 * Given a number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 *
 * Tags: Array, Math
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; --i) {
            result.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
        if (carry == 1)
            result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        vector<int> digits;
        transform(line.begin(), line.end(),
                back_inserter(digits), [](char c){ return c - '0'; });
        auto result = Solution().plusOne(digits);
        copy(result.begin(), result.end(), ostream_iterator<int>(cout, ""));
        cout << endl;
    }
    return 0;
}
