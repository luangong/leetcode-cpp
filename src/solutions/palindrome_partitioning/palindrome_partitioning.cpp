/**
 * Palindrome Partitioning
 *
 * Given a string s, partition s such that every substring of the partition is a
 * palindrome.
 *
 * Return all possible palindrome partitionings of s.
 *
 * For example, given s = "aab", return
 *
 *   [
 *     ["aa", "b"],
 *     ["a", "a", "b"]
 *   ]
 *
 * Tags: Backtracking
 */

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> palindrome(s.size(), vector<bool>(s.size()));
        isPalindrome(s, palindrome);
        return partition(s, 0, palindrome);
    }

    vector<vector<string>> partition(const string& s, int start, const vector<vector<bool>>& palindrome) {
        vector<vector<string>> result;
        for (int i = start; i < s.size(); ++i) {
            if (palindrome[start][i]) {
                vector<vector<string>> tmp = partition(s, i+1, palindrome);
                for (auto& vec : tmp) {
                    vec.insert(vec.begin(), s.substr(start, i-start+1));
                    result.push_back(vec);
                }
            }
        }

        // 如果字符串 s[start..s.size()-1] 本身就是 palindrome，
        // 则 s[start..s.size()-1] 本身也是一种合法的划分
        if (start < s.size() && palindrome[start][s.size()-1])
            result.push_back(vector<string>{s.substr(start, s.size()-start)});
        return result;
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
    while (getline(cin, line)) {
        vector<vector<string>> result = sln.partition(line);
        for (const auto& vec : result) {
            copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, " "));
            cout << endl;
        }
    }
    return 0;
}
