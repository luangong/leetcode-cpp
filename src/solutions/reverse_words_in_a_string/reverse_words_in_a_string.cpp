/**
 * Reverse Words in a String
 *
 * Given an input string, reverse the string word by word.
 *
 * For example,
 *
 *   Given s = "the sky is blue",
 *   return "blue is sky the".
 *
 * For C programmers, try to solve it in-place in O(1) space.
 *
 * Clarification:
 *
 *   - What constitutes a word?
 *     A sequence of non-space characters constitutes a word.
 *
 *   - Could the input string contain leading or trailing spaces?
 *     Yes. However, your reversed string should not contain leading or trailing
 *     spaces.
 *
 *   - How about multiple spaces between two words?
 *     Reduce them to a single space in the reversed string.
 *
 * Tags: String
 */
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

class Solution {
 public:
  void reverseWords(std::string& s) {
    trim(s);
    std::reverse(s.begin(), s.end());
    std::string::size_type start = 0, end = 0;
    while (start < s.size()) {
      end = start + 1;
      while (end < s.size() && !isspace(s[end])) {
        ++end;
      }
      std::reverse(s.begin() + start, s.begin() + end);
      start = end + 1;
      // while (start < s.size() && isspace(s[start])) {
      //   ++start;
      // }
    }
  }

 private:
  /**
    * Removes leading and trailing spaces, as well as redundant spaces between
    * adjacent words.  The trimming is done in place.
    */
  void trim(std::string& s) {
    std::string::size_type i = 0;
    std::string::size_type j = s.find_first_not_of(" ");
    std::string::size_type last_char_pos = s.find_last_not_of(" ");
    while (j < last_char_pos + 1) {
      if (!std::isspace(s[j]) || !std::isspace(s[j-1])) {
        s[i++] = s[j];
      }
      ++j;
    }
    s.resize(i);
  }
};
