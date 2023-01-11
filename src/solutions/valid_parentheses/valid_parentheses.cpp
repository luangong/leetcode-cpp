/**
 * Valid Parentheses
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid
 * but "(]" and "([)]" are not.
 *
 * Tags: Stack, String
 */

#include <iostream>
#include <string>
#include <stack>

class Solution {
  public:
    bool isValid(const std::string& s) {
        std::stack<char> stk;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            } else if (stk.empty()) {
                return false;
            } else if ((stk.top() == '(' && ch == ')') ||
                    (stk.top() == '{' && ch == '}') ||
                    (stk.top() == '[' && ch == ']')) {
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};


int main(int argc, char **argv) {
    std::string s;
    while (std::getline(std::cin, s)) {
        std::cout << Solution().isValid(s) << std::endl;
    }
    return 0;
}
