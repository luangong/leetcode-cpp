/*
 * Longest Common Prefix
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * Tags: String
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < strs.size(); ++j)
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
        }
        return strs[0];
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<string> strs((istream_iterator<string>(iss)), istream_iterator<string>());
        cout << Solution().longestCommonPrefix(strs) << endl;
    }
    return 0;
}
