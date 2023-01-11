/**
 * Wildcard Matching
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 *
 *    bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 *
 *    isMatch("aa", "a")      => false
 *    isMatch("aa", "aa")     => true
 *    isMatch("aaa", "aa")    => false
 *    isMatch("aa", "*")      => true
 *    isMatch("aa", "a*")     => true
 *    isMatch("ab", "?*")     => true
 *    isMatch("aab", "c*a*b") => false
 *
 * Tags: Dynamic Programming, Backtracking, Greedy, String
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *text, const char *pattern) {
        if (*pattern == '*') {
            // Skip consecutive '*'s
            while (*pattern == '*')
                ++pattern;
            // If all remaining characters are '*'s, then it's a match
            if (*pattern == '\0')
                return true;
            // If pattern matches any of suffixes of text, then it's a match
            while (*text != '\0' && !isMatch(text, pattern))
                ++text;
            return *text != '\0';
        } else if (*text == '\0' || *pattern == '\0') {
            return *text == *pattern;
        } else if (*pattern == '?' || *text == *pattern) {
            return isMatch(text + 1, pattern + 1);
        } else {
            return false;
        }
    }

    bool isMatch2(const char *s, const char *p) {
        const char *star = nullptr;
        const char *ss = s;
        while (*s != '\0') {
            // Advance both pointers when (both characters match) or ('?' found
            // in pattern).  Note that *p will not advance beyond its length
            if (*p == '?' || *p == *s) { s++; p++; continue; }

            // '*' found in pattern, track index of '*', only advancing pattern
            // pointer
            if (*p == '*') { star = p++; ss = s; continue; }

            // Current characters don't match, last pattern pointer was '*',
            // current pattern pointer is not '*' only advancing pattern pointer
            if (star != nullptr) { p = star + 1; s = ++ss; continue; }

            // Current pattern pointer is not star, last patter pointer was not *
            // characters do not match
            return false;
        }

        // Check for remaining characters in pattern
        while (*p == '*')
            p++;
        return *p == '\0';
    }
};

int main(int argc, char **argv) {
    Solution sln;
    cout << sln.isMatch2("*bc", "*c") << endl;
    return 0;
}
