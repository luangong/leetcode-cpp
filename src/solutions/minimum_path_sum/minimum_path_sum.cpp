/**
 * Minimum Path Sum
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Tags: Dynamic Programming
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t n = grid.size();
        size_t m = grid[0].size();
        vector<vector<int>> path_sum(n, vector<int>(m));
        path_sum[0][0] = grid[0][0];
        for (int j = 1; j < m; ++j)
            path_sum[0][j] = path_sum[0][j-1] + grid[0][j];
        for (int i = 1; i < n; ++i) {
            path_sum[i][0] = path_sum[i-1][0] + grid[i][0];
            for (int j = 1; j < m; ++j)
                path_sum[i][j] = min(path_sum[i-1][j], path_sum[i][j-1]) + grid[i][j];
        }
        return path_sum[n-1][m-1];
    }

    /* 用一维滚动数组把空间复杂度优化到 O(m) */
    int minPathSum(vector<vector<int>>& grid) {
        auto n = grid.size();
        auto m = grid[0].size();
        vector<int> sum(m);
        sum[0] = grid[0][0];
        for (int j = 1; j < m; ++j)
            sum[j] = sum[j-1] + grid[0][j];
        for (int i = 1; i < n; ++i) {
            sum[0] = sum[0] + grid[i][0];
            for (int j = 1; j < m; ++j)
                sum[j] = min(sum[j-1], sum[j]) + grid[i][j];
        }
        return sum[m-1];    // sum.back();
    }

    /* 空间复杂度进一步优化到 O(min(n, m)) */
    int minPathSum(vector<vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();
        vector<int> sum(min(m, n));
        sum[0] = grid[0][0];
        for (int j = 1; j < min(m, n); ++j)
            sum[j] = sum[j-1] + (m >= n ? grid[0][j] : grid[j][0]);
        for (int i = 1; i < max(m, n); ++i) {
            sum[0] = sum[0] + (m >= n ? grid[i][0] : grid[0][i]);
            for (int j = 1; j < min(n, m); ++j)
                sum[j] = min(sum[j], sum[j-1]) + (m >= n ? grid[i][j] : grid[j][i]);
        }
        return sum.back();
    }
};
