/*
 * Length of Last Word
 *
 * Given a string s consists of upper/lower-case alphabets and space characters
 * ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * For example, given s = "Hello World", return 5
 *
 * Tags: String
 */

#include <cstring>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const string& s) {
        ssize_t end = s.size() - 1;
        while (end >= 0 && isspace(s[end]))
            --end;
        if (end < 0) return 0;
        ssize_t start = end - 1;
        while (start >= 0 && !isspace(s[start]))
            --start;
        return end - start;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string line;
    while (getline(cin, line))
        cout << sln.lengthOfLastWord(line) << "  \"" << line << "\""  << endl;
    return 0;
}
