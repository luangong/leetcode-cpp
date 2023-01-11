/**
 * Unique Paths
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths2(int m, int n) {
        --m, --n;
        if (m < n) swap(m, n);  // ensure that n <= m
        vector<vector<int>> comb(m+n+1, vector<int>(m+n+1, 1));
        for (int i = 1; i <= m+n; ++i)
            for (int j = 1; j < i; ++j)
                comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        return comb[m+n][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        // Ensure that n <= m
        if (m < n) swap(m, n);
        // Initialize. comb[x][0] == 1
        vector<int> dp(n, 1);
        // Iterate
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[j] = dp[j] + dp[j-1];
        return dp[n-1];
    }
};

int main(int argc, char **argv) {
    int m, n;
    Solution sln;
    while (cin >> m >> n)
        cout << sln.uniquePaths(m, n) << endl;
}
