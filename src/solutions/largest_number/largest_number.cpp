/**
 * Largest Number
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of
 * an integer.
 *
 * Credits: Special thanks to @ts for adding this problem and creating all test
 * cases.
 *
 * Tags: Sort
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> strs;
        transform(num.begin(), num.end(), back_inserter(strs),
                [](int x) { return to_string(x); });
        sort(strs.rbegin(), strs.rend(),
                [](const string &a, const string &b) { return a + b < b + a; });
        return accumulate(strs.begin(), strs.end(), string());
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> num((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().largestNumber(num) << endl;
    }
    return 0;
}
