/*
 * Letter Combinations of a Phone Number
 *
 * Given a digit string, return all possible letter combinations that the number
 * could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 *
 *    http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2
 *    .svg/200px-Telephone-keypad2.svg.png
 *
 * Input: Digit string "23"
 *
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * Note: Although the above answer is in lexicographical order, your answer
 * could be in any order you want.
 *
 * Tags: Backtracking, String
 */

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
private:
    const vector<string> letters = {
        "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string solution;
        backtrack(digits, solution, result);
        return result;
    }

    void backtrack(const string &digits, string &solution, vector<string> &result) {
        if (solution.size() == digits.size()) {
            result.push_back(solution);
            return;
        }
        for (char ch : letters[digits[solution.size()]-'2']) {
            solution.push_back(ch);
            backtrack(digits, solution, result);
            solution.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    string digits;
    while (cin >> digits) {
        // cout << "digits: " << digits << endl;
        vector<string> result = Solution().letterCombinations(digits);
        copy(result.begin(), result.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }
    return 0;
}
