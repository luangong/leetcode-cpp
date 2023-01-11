/*
Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while
preserving the order of characters.  No two characters may map to the same
character but a character may map to itself.

For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.

Note: You may assume both s and t have the same length.

Tags: Hash Table
*/


#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic2(const string &s, const string &t) {
        map<char, char> s2t, t2s;
        for (int i = 0; i < s.size(); ++i) {
            if (s2t.find(s[i]) != s2t.end() && s2t[s[i]] != t[i])
                return false;
            s2t[s[i]] = t[i];
            if (t2s.find(t[i]) != t2s.end() && t2s[t[i]] != s[i])
                return false;
            t2s[t[i]] = s[i];
        }
        return true;
    }

    bool isIsomorphic3(const string &s, const string &t) {
        char s2t[128] = {0};
        char t2s[128] = {0};
        for (int i = 0; i < s.size(); ++i) {
            if (s2t[s[i]] != '\0' && s2t[s[i]] != t[i])
                return false;
            s2t[s[i]] = t[i];
            if (t2s[t[i]] != '\0' && t2s[t[i]] != s[i])
                return false;
            t2s[t[i]] = s[i];
        }
        return true;
    }

    bool isIsomorphic(const string &s, const string &t) {
        int map1[128] = {0};
        int map2[128] = {0};
        for (int i = 0; i < s.size(); ++i) {
            if (map1[s[i]] != map2[t[i]])
                return false;
            map1[s[i]] = map2[t[i]] = i+1;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    string s, t;
    while (cin >> s >> t)
        cout << Solution().isIsomorphic(s, t) << endl;
    return 0;
}
