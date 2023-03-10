/**
 * Valid Palindrome
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * For example, "A man, a plan, a canal: Panama" is a palindrome. "race a car"
 * is not a palindrome.
 *
 * Note: Have you consider that the string might be empty? This is a good
 * question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 * Tags: Two Pointers, String
 */
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (!isalnum(s[i]))
                ++i;
            else if (!isalnum(s[j]))
                --j;
            else if (tolower(s[i]) != tolower(s[j]))
                return false;
            else
                ++i, --j;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string line;
    while (getline(cin, line))
        cout << sln.isPalindrome(line) << endl;
    return 0;
}
