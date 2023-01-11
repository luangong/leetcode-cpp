/**
 * Unique Paths II
 *
 * Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example, there is one obstacle in the middle of a 3 x 3 grid as
 * illustrated below.
 *
 *   [
 *     [0,0,0],
 *     [0,1,0],
 *     [0,0,0]
 *   ]
 *
 * The total number of unique paths is 2.
 * Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0] != 1 ? 1 : 0;
        for (int j = 1; j < n; ++j)
            dp[0][j] = (grid[0][j] != 1 ? dp[0][j-1] : 0);
        for (int i = 1; i < m; ++i) {
            dp[i][0] = (grid[i][0] != 1 ? dp[i-1][0] : 0);
            for (int j = 1; j < n; ++j)
                if (grid[i][j] != 1)
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
        return dp[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        auto n = grid.size();
        auto m = grid[0].size();
        vector<int> dp(m, 0);
        dp[0] = (grid[0][0] != 1 ? 1 : 0);
        for (int i = 0; i < n; ++i) {
            dp[0] = (grid[i][0] != 1 ? dp[0] : 0);
            for (int j = 1; j < m; ++j)
                dp[j] = (grid[i][j] != 1 ? dp[j] + dp[j-1] : 0);
        }
        return dp.back();
    }
};
