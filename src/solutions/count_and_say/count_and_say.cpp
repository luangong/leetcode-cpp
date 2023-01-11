/**
 * Count and Say
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 *
 *    1, 11, 21, 1211, 111221, ...
 *
 *    1 is read off as "one 1" or 11.
 *    11 is read off as "two 1s" or 21.
 *    21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 *
 * Tags: String
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n > 0)
            s = countAndSay(s);
        return s;
    }

    string countAndSay(const string& s) {
        ostringstream oss;
        int count = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                ++count;
            } else {
                oss << count << s[i-1];
                count = 1;
            }
        }
        oss << count << s[s.size()-1];
        return oss.str();
    }
};

int main(int argc, char **argv) {
    int n;
    while (cin >> n)
        cout << Solution().countAndSay(n) << endl;
    return 0;
}
