/**
 * Anagrams
 *
 * Given an array of strings, return all groups of strings that are anagrams.
 * Note: All inputs will be in lower-case.
 *
 * Tags: String, Hash Table
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            string normalized(s);
            sort(normalized.begin(), normalized.end());
            groups[normalized].push_back(s);
        }
        vector<string> result;
        for (const auto& pair : groups) {
            const auto& group = pair.second;
            if (group.size() >= 2)
                result.insert(result.end(), group.begin(), group.end());
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<string> words((istream_iterator<string>(iss)), istream_iterator<string>());
        vector<string> result = Solution().anagrams(words);
        copy(result.begin(), result.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }
    return 0;
}
