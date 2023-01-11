/**
 * Implement strStr().
 *
 * Returns a pointer to the first occurrence of pattern in text, or NULL if
 * pattern is not part of text.
 *
 * Update (2014-11-02):
 *
 * The signature of the function had been updated to return the index instead
 * of the pointer.  If you still see your function signature returns a char * or
 * String, please click the reload button  to reset your code definition.
 *
 * Tags: Two Pointers, String
 */
class Solution {
 public:
  int strStr(string text, string pattern) {
    return text.find(pattern);
  }

  int strStr(const string& text, const string& pattern) {
    std::size_t m = text.size();
    std::size_t n = pattern.size();
    for (int start = 0; start < m-n+1; ++start) {
      int i = 0;
      for (; i < n; ++i) {
        if (text[start+i] != pattern[i]) {
          break;
        }
      }
      if (i == n) {
        return s;
      }
    }
    return -1;
  }

  int strStr(string text, string pattern) {
    decltype(text.size()) i = 0, j = 0;
    while (i < text.size() && j < pattern.size()) {
      if (text[i] == pattern[j]) {
        ++i, ++j;
      } else {
        i = i - j + 1;
        j = 0;
      }
    }
    if (j == pattern.size()) {
      return i - pattern.size();
    }
    return -1;
  }
};
