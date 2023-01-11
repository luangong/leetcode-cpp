/**
 * Search a 2D Matrix
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 *    - Integers in each row are sorted from left to right.
 *    - The first integer of each row is greater than the last integer of the
 *      previous row.
 *
 * For example, consider the following matrix:
 *
 *    [
 *       [1,   3,  5,  7],
 *       [10, 11, 16, 20],
 *       [23, 30, 34, 50]
 *    ]
 *
 * Given target = 3, return true.
 *
 * Tags: Array, Binary Search
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / n, c = mid % n;
            if (matrix[r][c] < target)
                low = mid + 1;
            else if (matrix[r][c] > target)
                high = mid - 1;
            else
                return true;
        }
        return false;
    }
};
