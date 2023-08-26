/**
 * Palindrome Partitioning II
 *
 * Given a string s, partition s such that every substring of the partition is a
 * palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab", return 1 since the palindrome partitioning
 * ["aa", "b"] could be produced using 1 cut.
 *
 * Tags: Dynamic Programming
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(const string& s) {
        vector<vector<bool>> palindrome(s.size(), vector<bool>(s.size(), false));
        isPalindrome(s, palindrome);
        vector<int> c(s.size(), numeric_limits<int>::max());
        for (int i = 0; i < s.size(); ++i) {
            if (palindrome[0][i]) {
                c[i] = 0;
                continue;
            }
            int m = numeric_limits<int>::max();
            for (int j = 1; j <= i; ++j) {
                if (palindrome[j][i])
                    m = min(m, c[j-1]);
            }
            c[i] = m + 1;
        }
        return c[s.size()-1];
    }

    void isPalindrome(const string& s, vector<vector<bool>>& palindrome) {
        for (int i = 0; i < s.size(); ++i)
            palindrome[i][i] = true;
        for (int i = 0; i < s.size() - 1; ++i)
            palindrome[i][i+1] = (s[i] == s[i+1]);
        for (int len = 3; len <= s.size(); ++len) {
            for (int i = 0; i + len <= s.size(); ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && palindrome[i+1][j-1])
                    palindrome[i][j] = true;
                else
                    palindrome[i][j] = false;
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string line;
    while (getline(cin, line))
        cout << sln.minCut(line) << endl;
    return 0;
}
