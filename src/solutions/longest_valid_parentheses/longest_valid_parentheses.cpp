/**
 * Longest Valid Parentheses
 *
 * Given a string containing just the characters '(' and ')', find the length of
 * the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length
 * of 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is
 * "()()", which has length of 4.
 *
 * Tags: Dynamic Programming, String
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses2(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            // 遇到 ( 就把 index 保存到栈上
            if (s[i] == '(') {
                stk.push(i);
            }
            // 遇到 ) 就把配对的 () 都改成 -
            else if (!stk.empty()) {
                s[i] = '-';
                s[stk.top()] = '-';
                stk.pop();
            }
        }
        int length = 0, max_length = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '-') {
                ++length;
                max_length = max(max_length, length);
            } else {
                length = 0;
            }
        }
        max_length = max(max_length, length);
        return max_length;
    }

    int longestValidParentheses(const string& s) {
        int max_length = 0;
        stack<int> stk;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (!stk.empty()) {
                stk.pop();
                if (stk.empty())
                    max_length = max(max_length, i - start);
                else
                    max_length = max(max_length, i - stk.top());
            } else {
                start = i;
            }
        }
        return max_length;
    }
};

int main(int argc, char **argv) {
    string str;
    while (cin >> str)
        cout << Solution().longestValidParentheses(str) << endl;
    return 0;
}
