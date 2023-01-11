#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    const static int power = 262144;        // 4 ^ 9
    vector<string> findRepeatedDnaSequences(const string &s) {
        vector<string> result;
        if (s.length() <= 10)
            return result;
        // unordered_map<int, int> count {{ h, 1 }};
        int count[1048576] = {0};           // 4 ^ 10
        int hash = 0;
        for (int i = 0; i < 10; ++i)
            hash = hash * 4 + digit(s[i]);
        count[hash] = 1;
        for (int i = 10; i <= s.length()-10; ++i) {
            hash = 4 * (hash - power * digit(s[i-1])) + digit(s[i+9]);
            if (++count[hash] == 2)
                result.push_back(s.substr(i, 10));
        }
        return result;
    }

    int digit(char c) {
        // const static map = {
        //     { 'A', 0 }, { 'C', 1 },
        //     { 'G', 2 }, { 'T', 3 }
        // };

        // 'A' - 'A' + 1 = 1  = 1 (mod 5)
        // 'C' - 'A' + 1 = 3  = 3 (mod 5)
        // 'G' - 'A' + 1 = 7  = 2 (mod 5)
        // 'T' - 'A' + 1 = 20 = 0 (mod 5)

        // Idea from https://leetcode.com/discuss/29623/11ms-solution-with-unified-hash-fxn
        return (c - 'A' + 1) % 5;
    }

    // int hash(const string &s) {
    //     int h = 0;
    //     for (char c : s)
    //         h = h * 4 + digit(c);
    //     return h;
    // }

    vector<string> findRepeatedDnaSequences2(string s) {
        vector<string> result;
        unordered_map<string, int> count;
        for (int i = 0; i <= int(s.size())-10; ++i)
            if (++count[s.substr(i,10)] == 2)
                result.push_back(s.substr(i,10));
        return result;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        vector<string> sequences = Solution().findRepeatedDnaSequences(line);
        copy(sequences.begin(), sequences.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }
    return 0;
}
