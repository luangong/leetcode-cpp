/**
 * Spiral Matrix II
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n^2 in spiral order.
 *
 * For example, given n = 3, you should return the following matrix:
 *
 *   [
 *     [ 1, 2, 3 ],
 *     [ 8, 9, 4 ],
 *     [ 7, 6, 5 ]
 *   ]
 *
 * Tags: Array
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        if (n == 0) return matrix;
        ssize_t first_col = 0, last_col = n-1;
        ssize_t first_row = 0, last_row = n-1;
        int num = 1;
        while (true) {
            for (ssize_t j = first_col; j <= last_col; ++j)
                matrix[first_row][j] = num++;
            if (++first_row > last_row) break;
            for (ssize_t i = first_row; i <= last_row; ++i)
                matrix[i][last_col] = num++;
            if (first_col > --last_col) break;
            for (ssize_t j = last_col; j >= first_col; --j)
                matrix[last_row][j] = num++;
            if (first_row > --last_row) break;
            for (ssize_t i = last_row; i >= first_row; --i)
                matrix[i][first_col] = num++;
            if (++first_col > last_col) break;
        }
        return matrix;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    int n;
    while (cin >> n) {
        auto matrix = sln.generateMatrix(n);
        for (const auto& row: matrix) {
            for (const auto& cell: row)
                cout << cell << ' ';
            cout << endl;
        }
    }
    return 0;
}
