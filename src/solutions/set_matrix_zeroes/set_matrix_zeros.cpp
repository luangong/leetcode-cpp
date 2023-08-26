/**
 * Set Matrix Zeros
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0.
 * Do it in place.
 *
 * Follow up:
 *
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m+n) space, but still not the best solution.
 * Could you devise a constant space solution?
 *
 * Tags: Array
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> clone(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (clone[i][j] == 0) {
                    fill_n(&matrix[i][0], m, 0);
                    for (int row = 0; row < n; ++row)
                        matrix[row][j] = 0;
                }
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> row_has_zero(n, false);
        vector<bool> col_has_zero(m, false);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (matrix[i][j] == 0)
                    row_has_zero[i] = col_has_zero[j] = true;
        for (int i = 0; i < n; ++i)
            if (row_has_zero[i])
                fill_n(&matrix[i][0], m, 0);
        for (int j = 0; j < m; ++j)
            if (col_has_zero[j])
                for (int i = 0; i < n; ++i)
                    matrix[i][j] = 0;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool first_row_has_zero = false;
        bool first_col_has_zero = false;
        for (int j = 0; j < m; ++j)
            if (matrix[0][j] == 0)
                first_row_has_zero = true;
        for (int i = 0; i < n; ++i)
            if (matrix[i][0] == 0)
                first_col_has_zero = true;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        for (int i = 1; i < n; ++i)
            if (matrix[i][0] == 0)
                fill_n(&matrix[i][0], m, 0);
        for (int j = 1; j < m; ++j)
            if (matrix[0][j] == 0)
                for (int i = 0; i < n; ++i)
                    matrix[i][j] = 0;
        if (first_row_has_zero)
            fill_n(&matrix[0][0], m, 0);
        if (first_col_has_zero)
            for (int i = 0; i < n; ++i)
                matrix[i][0] = 0;
    }
};
