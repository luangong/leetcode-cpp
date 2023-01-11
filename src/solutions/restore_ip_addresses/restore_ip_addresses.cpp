/**
 * Restore IP Addresses
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * For example: given "25525511135",
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 * Tags: Backtracking, String
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

string join(const vector<string>& vec, const string& delimiter) {
    string result;
    if (!vec.empty())
        result += vec[0];
    for (int i = 1; i < vec.size(); ++i)
        result += delimiter + vec[i];
    return result;
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> addresses;
        vector<string> parts;
        backtrack(s, parts, 0, addresses);
        return addresses;
    }

    void backtrack(const string& s, vector<string>& parts, int start, vector<string>& addresses) {
        if (parts.size() == 4 && start == s.size()) {
            addresses.push_back(join(parts, "."));
            return;
        }
        if (parts.size() > 4) return;
        for (int len = 1; len <= 3 && start+len <= s.size(); ++len) {
            if (stoi(s.substr(start, len)) > 255 || (len > 1 && s[start] == '0'))
                continue;
            parts.push_back(s.substr(start, len));
            backtrack(s, parts, start+len, addresses);
            parts.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        auto addresses = Solution().restoreIpAddresses(line);
        cout << join(addresses, ", ") << endl;
    }
    return 0;
}
