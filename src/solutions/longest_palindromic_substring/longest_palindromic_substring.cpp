/*
 * Longest Palindromic Substring
 *
 * Given a string S, find the longest palindromic substring in S.  You may assume that the
 * maximum length of S is 1000, and there exists one unique longest palindromic substring.
 *
 * Tags: String
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  string longestPalindrome(const string& s) {
    // vector<vector<bool>> palindrome(s.size(), vector<bool>(s.size(), false));
    // isPalindrome(s, palindrome);
    // vector<vector<char>> palindrome(s.size(), vector<char>(s.size(), -1));
    /*
    for (int len = s.size(); len >= 1; --len) {
      for (int i = 0; i + len <= s.size(); ++i) {
        int j = i + len - 1;
        if (isPalindrome(s, i, j)) {
          return s.substr(i, len);
        }
      }
    }
    */

    int start = 0, max_length = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (i-max_length-1 >= 0 && isPalindrome(s, i-max_length-1, i)) {
        start = i - max_length - 1;
        max_length += 2;
      } else if (isPalindrome(s, i-max_length, i)) {
        start = i - max_length;
        max_length += 1;
      }
    }
    return s.substr(start, max_length);

    /*
    int max_length = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = s.size()-1; j >= i; --j) {
        if (isPalindrome(s, i, j)) {
          max_length = max(max_length, j-i+1);
        }
      }
    }
    */
    return "";
  }

  /**
   * Bottom-up 计算出所有的 substring 是否为 palindrome
   */
  void cachePalindrome(const string& s, vector<vector<bool>>& palindrome) {
    // Single character substring
    for (int i = 0; i < s.size(); ++i) {
      palindrome[i][i] = true;
    }

    // Double character substring
    for (int i = 0; i < s.size() - 1; ++i) {
      palindrome[i][i+1] = (s[i] == s[i+1]);
    }

    // Substrings with length > 2
    for (int len = 3; len <= s.size(); ++len) {
      for (int i = 0; i + len <= s.size(); ++i) {
        int j = i + len - 1;
        palindrome[i][j] = (s[i] == s[j] && palindrome[i+1][j-1]);
      }
    }
  }

  /*
   * Top-down 备忘录方法，可避免 bottom-up 的 worst-case。注意此处为了用一个
   * 值来标记 palindrome 矩阵是否已经计算过，不能再用 bool 类型了，为了节省
   * 空间，用了 char 类型
   */
  bool isPalindrome(const string& s, int i, int j, vector<vector<char>>& palindrome) {
    if (palindrome[i][j] != -1) { // -1 表示还没计算过
      return palindrome[i][j];
    }
    if (i == j) {
      palindrome[i][j] = true;
    } else if (i+1 == j) {
      palindrome[i][j] = (s[i] == s[j]);
    } else {
      palindrome[i][j] = (s[i] == s[j] && isPalindrome(s, i+1, j-1, palindrome));
    }
    return palindrome[i][j];
  }

  /*
   * LeetCode 上用 memoization 又会导致 Memory Limit Exceeded，所以这样干脆
   * 不用查找表，直接递归计算。这样做虽然过了 large test case，但感觉会导致
   * 重复计算，不是很好。。。
   */
  bool isPalindrome(const string& s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }
    return true;
  }
};
