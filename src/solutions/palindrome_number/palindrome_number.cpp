/**
 * Palindrome Number
 *
 * Determine whether an integer is a palindrome.  Do this without extra space.
 *
 * Some hints:
 *
 * Could negative integers be palindromes? (e.g., -1)
 *
 * If you are thinking of converting the integer to string, note the restriction
 * of using extra space.
 *
 * You could also try reversing an integer.  However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might overflow.
 * How would you handle such case?
 *
 * There is a more generic way of solving this problem.
 *
 * Tags: Math
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div = 1;
        while (x / div >= 10)
            div *= 10;
        while (x != 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    int x;
    while (cin >> x)
        cout << (sln.isPalindrome(x) ? "true" : "false") << endl;
    return 0;
}
