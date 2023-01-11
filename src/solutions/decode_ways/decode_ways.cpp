/**
 * Decode Ways
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *    'A' -> 1
 *    'B' -> 2
 *    ...
 *    'Z' -> 26
 *
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 *
 * For example, given encoded message "12", it could be decoded as "AB" (1 2) or
 * "L" (12).
 *
 * The number of ways decoding "12" is 2.
 *
 * Tags: Dynamic Programming, String
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> numDecodings(s.size());
        // Base cases
        numDecodings[0] = (s[0] == '0') ? 0 : 1;
        if (s.size() >= 2) {
            if (s[0] == '0')
                numDecodings[1] = 0;
            else if (s[0] == '1' && s[1] == '0')
                numDecodings[1] = 1;
            else if (s[0] == '1' && s[1] != '0')
                numDecodings[1] = 2;
            else if (s[0] == '2' && '1' <= s[1] && s[1] <= '6')
                numDecodings[1] = 2;
            else if (s[0] == '2' && s[1] > '6')
                numDecodings[1] = 1;
            else if (s[0] == '3' && s[1] == '0')
                numDecodings[1] = 0;
            else if (s[0] >= '3' && s[1] != '0')
                numDecodings[1] = 1;
        }

        // Loop
        for (int i = 2; i < s.size(); ++i) {
            if (s[i-1] == '0')
                numDecodings[i] = (s[i] == '0' ? 0 : numDecodings[i-1]);
            else if (s[i-1] == '1' && s[i] == '0')
                numDecodings[i] = numDecodings[i-2];
            else if (s[i-1] == '1' && s[i] != '0')
                numDecodings[i] = numDecodings[i-2] + numDecodings[i-1];
            else if (s[i-1] == '2' && s[i] == '0')
                numDecodings[i] = numDecodings[i-2];
            else if (s[i-1] == '2' && '1' <= s[i] && s[i] <= '6')
                numDecodings[i] = numDecodings[i-2] + numDecodings[i-1];
            else if (s[i-1] == '2' && s[i] > '6')
                numDecodings[i] = numDecodings[i-1];
            else if (s[i-1] >= '3' && s[i] == '0')
                numDecodings[i] = 0;
            else if (s[i-1] >= '3' && s[i] != '0')
                numDecodings[i] = numDecodings[i-1];
        }

        return numDecodings[s.size()-1];
    }
};

int main(int argc, char **argv) {
    string s;
    while (cin >> s)
        cout << Solution().numDecodings(s) << endl;
    return 0;
}
