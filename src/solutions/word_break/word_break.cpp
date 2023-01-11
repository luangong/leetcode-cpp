/**
 * Word Break
 *
 * Given a string s and a dictionary of words dict, determine if s can be
 * segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 *
 * Tags: Dynamic Programming
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Whether empty string is breakable is undefined on LeetCode
    bool wordBreak2(const string& s, const unordered_set<string>& dict) {
        if (dict.find(s) != dict.end())
            return true;
        for (int i = 1; i < s.size(); ++i)
            if (dict.find(s.substr(0, i)) != dict.end()
                    && wordBreak(s.substr(i), dict))
                return true;
        return false;
    }

    // Whether empty string is breakable is undefined on LeetCode
    bool wordBreak(const string& s, const unordered_set<string>& dict) {
        vector<bool> breakable(s.size()+1, false);
        breakable[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (breakable[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    breakable[i] = true;
                    break;
                }
            }
        }
        return breakable[s.size()];
    }
};

int main(int argc, char **argv) {
    while (cin) {
        string s, line;
        getline(cin, s);
        getline(cin, line);
        istringstream iss(line);
        unordered_set<string> dict((istream_iterator<string>(iss)), istream_iterator<string>());
        cout << Solution().wordBreak(s, dict) << endl;
    }
    return 0;
}
