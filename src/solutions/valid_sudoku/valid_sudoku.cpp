/**
 * Valid Sudoku
 *
 * Determine if a Sudoku is valid, according to: [Sudoku Puzzles --- The Rules]
 * (http://sudoku.com.au/TheRules.aspx).
 *
 *    - Each row must have the numbers 1-9 seening just once.
 *    - Each column must have the numbers 1-9 seening just once.
 *    - And the numbers 1-9 must seen just once in each of the 9 sub-boxes of
 *      the grid.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with
 * the character '.'.
 *
 * http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-
 * 20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
 *
 *              +---+---+---+---+---+---+---+---+---+
 *              | 5 | 3 |   |   | 7 |   |   |   |   |
 *              +---+---+---+---+---+---+---+---+---+
 *              | 6 |   |   | 1 | 9 | 5 |   |   |   |
 *              +---+---+---+---+---+---+---+---+---+
 *              |   | 9 | 8 |   |   |   |   | 6 |   |
 *              +---+---+---+---+---+---+---+---+---+
 *              | 8 |   |   |   | 6 |   |   |   | 3 |
 *              +---+---+---+---+---+---+---+---+---+
 *              | 4 |   |   | 8 |   | 3 |   |   | 1 |
 *              +---+---+---+---+---+---+---+---+---+
 *              | 7 |   |   |   | 2 |   |   |   | 6 |
 *              +---+---+---+---+---+---+---+---+---+
 *              |   | 6 |   |   |   |   | 2 | 8 |   |
 *              +---+---+---+---+---+---+---+---+---+
 *              |   |   |   | 4 | 1 | 9 |   |   | 5 |
 *              +---+---+---+---+---+---+---+---+---+
 *              |   |   |   |   | 8 |   |   | 7 | 9 |
 *              +---+---+---+---+---+---+---+---+---+
 *
 * A partially filled sudoku which is valid.
 *
 * Note: A valid Sudoku board (partially filled) is not necessarily solvable.
 * Only the filled cells need to be validated.
 *
 * Tags: Hash Table
 */

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(char c, vector<bool>& seen) {
        if (c == '.')
            return true;
        else if (seen[c-'1'])
            return false;
        else {
            seen[c-'1'] = true;
            return true;
        }
    }

    bool isValidSudoku(vector<vector<char>> &board) {

        // 检查每行是否有效
        for (int i = 0; i < board.size(); ++i) {
            vector<bool> seen(9, false);
            for (int j = 0; j < 9; ++j)
                if (!check(board[i][j], seen))
                    return false;
        }

        // 检查每列是否有效
        for (int j = 0; j < 9; ++j) {
            vector<bool> seen(9, false);
            for (int i = 0; i < 9; ++i)
                if (!check(board[i][j], seen))
                    return false;
        }

        // 检查每个田字格是否有效
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                vector<bool> seen(9, false);
                for (int i = 0; i < 3; ++i)
                    for (int j = 0; j < 3; ++j)
                        if (!check(board[r*3+i][c*3+j], seen))
                            return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    /*
    while (cin.good()) {
        vector<vector<char>> board;
        for (int i = 0; i < 9; ++i) {
            string line;
            getline(cin, line);
            board.push_back(vector<char>(line.begin(), line.end()));
            copy(board.back().begin(), board.back().end(), ostream_iterator<char>(cout, ""));
            cout << endl;
        }
    }
    */
    for (int i = 0; i < 81; ++i) {
        string line;
        getline(cin, line);
    }
    cin.get();
    cout << bool(cin) << endl;
    return 0;
}
