/**
 * N-Queens
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard
 * such that no two queens attack each other.
 *
 *    http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 * For example, there exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *   [".Q..",  // Solution 1
 *    "...Q",
 *    "Q...",
 *    "..Q."],
 *
 *   ["..Q.",  // Solution 2
 *    "Q...",
 *    "...Q",
 *    ".Q.."]
 * ]
 *
 * Tags: Backtracking
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> sln(n);
        vector<vector<string>> result;
        backtrack(sln, 0, result);
        return result;
    }

    void backtrack(vector<int>& sln, int k, vector<vector<string>>& result) {
        if (k == sln.size()) {
            vector<string> chessBoard;
            for (int i = 0; i < sln.size(); ++i) {
                string line;
                for (int j = 0; j < sln[i]; ++j)
                    line += '.';
                line += 'Q';
                for (int j = sln[i]+1; j < sln.size(); ++j)
                    line += '.';
                chessBoard.push_back(line);
            }
            result.push_back(chessBoard);
            return;
        }

        for (int i = 0; i < sln.size(); ++i) {
            if (isValidPos(sln, k, i)) {
                sln[k] = i;
                backtrack(sln, k+1, result);
            }
        }
    }

    bool isValidPos(const vector<int>& sln, int k, int i) {
        for (int j = 0; j < k; ++j)
            if (i == sln[j] || abs(sln[j]-i) == k-i)
                return false;
        return true;
    }

    vector<vector<string>> convert(const vector<int>& solution) {
    }
};

int main(int argc, char **argv) {
    int n;
    while (cin >> n) {
        Solution sln;
        vector<vector<string>> result = sln.solveNQueens(n);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j)
                cout << result[i][j] << endl;
            cout << endl;
        }
    }
    return 0;
}
