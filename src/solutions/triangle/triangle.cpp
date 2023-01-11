/**
 * Triangle
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step you
 * may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 *   [
 *        [2],
 *       [3,4],
 *      [6,5,7],
 *     [4,1,8,3]
 *   ]
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note: Bonus point if you are able to do this using only O(n) extra space,
 * where n is the total number of rows in the triangle.
 *
 * Tags: Array, Dynamic Programming
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<vector<int>> m(triangle.size());
        // Base case
        m.back() = triangle.back();
        // Bottom up
        for (int i = triangle.size()-2; i >= 0; --i) {
            m[i].resize(triangle[i].size());
            for (int j = 0; j < triangle[i].size(); ++j)
                m[i][j] = triangle[i][j] + min(m[i+1][j], m[i+1][j+1]);
        }
        return m[0][0];
    }

    // O(n) space only
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> m(triangle.back());
        for (int i = triangle.size()-2; i >= 0; --i)
            for (int j = 0; j < triangle[i].size(); ++j)
                m[j] = triangle[i][j] + min(m[j], m[j+1]);
        return m[0];
    }
};
