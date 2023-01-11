/**
 * Longest Substring without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.  For example, the longest substring without repeating letters for
 * "abcabcbb" is "abc", which the length is 3.  For "bbbbb" the longest
 * substring is "b", with the length of 1.
 *
 * Tags: Hash Table, Two Pointers, String
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Solution {
 public:
  // O(n) time, O(|Σ|) space, where |Σ| is the number of possible characters
  std::size_t lengthOfLongestSubstring(const std::string& s) {
    int max_length = 0;
    int start = 0;
    std::vector<bool> window(128);
    for (int i = 0; i < s.size(); ++i) {
      if (!window[s[i]]) {
        window[s[i]] = true;
      } else {
        max_length = std::max(max_length, i - start);
        while (s[start] != s[i]) {          // start a new substring
          window[s[start++]] = false;
        }
        ++start;
      }
    }

    // Update max length for the last substring
    return std::max(max_length, s.size() - start);
  }

  int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> index;
    int max_length = 0, start = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (index.find(s[i]) != index.end() && index[s[i]] >= start) {
        max_length = std::max(max_length, i - start);
        start = index[s[i]] + 1;
      }
      index[s[i]] = i;
    }
    return std::max(max_length, (int)s.size() - start);
  }
};


int main(int argc, char **argv) {
  Solution sln;
  std::string line;
  while (getline(cin, line)) {
    std::cout << sln.lengthOfLongestSubstring(line) << std::endl;
  }
  return 0;
}
