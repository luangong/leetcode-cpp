/*
 * Add Binary
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 *
 *    a = "11"
 *    b = "1"
 *    Return "100".
 *
 * Tags: Math, String
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        string sum;
        int carry = 0;
        for (int i = 0; i < max(m, n); ++i) {
            int ai = (i < m ? a[m-i-1] - '0' : 0);
            int bi = (i < n ? b[n-i-1] - '0' : 0);
            sum += (ai + bi + carry) % 2 + '0';
            carry = (ai + bi + carry) / 2;
        }
        if (carry == 1)
            sum += '1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main(int argc, char *argv[]) {
    string a, b;
    while (cin >> a >> b)
        cout << Solution().addBinary(a, b) << endl;
    return 0;
}
