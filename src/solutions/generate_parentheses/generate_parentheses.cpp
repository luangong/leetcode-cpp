/**
 * Generate Parentheses
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 * Tags: Backtracking, String
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string buf(n * 2, '\0');
        generateParenthesis(n, 0, 0, buf, result);
        return result;
    }

    void generateParenthesis(int openStock, int closeStock, int level, string& buf, vector<string>& result) {
        if (openStock == 0 && closeStock == 0) {
            result.push_back(buf);
            return;
        }
        if (openStock > 0) {
            buf[level] = '(';
            generateParenthesis(openStock-1, closeStock+1, level+1, buf, result);
        }
        if (closeStock > 0) {
            buf[level] = ')';
            generateParenthesis(openStock, closeStock-1, level+1, buf, result);
        }
    }
};

int main(int argc, char **argv) {
    int n;
    Solution sln;
    while (cin >> n) {
        vector<string> result = sln.generateParenthesis(n);
        for (size_t i = 0; i < result.size(); ++i)
            cout << result[i] << endl;
    }
    return 0;
}
