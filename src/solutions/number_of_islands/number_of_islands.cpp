/*
 * Number of Islands
 *
 * Given a 2d grid map of 1's (land) and 0's (water), count the number of
 * islands.  An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically.  You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1
 *
 *   11110
 *   11010
 *   11000
 *   00000
 *
 * Answer: 1
 *
 * Example 2
 *
 *   11000
 *   11000
 *   00100
 *   00011
 *
 * Answer: 3
 *
 * CREDITS: Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    count += 1;
                    BFS(grid, i, j);
                }
            }
        }
        return count;
    }

    // Check if the current position is valid
    bool isValid(const vector<vector<char>> &grid, int i, int j) {
        return 0 <= i && i < grid.size() &&
               0 <= j && j < grid[0].size() &&
               grid[i][j] == '1';
    }

    // DFS with recursion
    void DFS(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        for (auto index : { make_pair(i-1,j), make_pair(i+1,j), make_pair(i,j-1), make_pair(i,j+1) })
            if (isValid(grid, index.first, index.second))
                DFS(grid, index.first, index.second);
    }

    // DFS with a stack
    void DFS2(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        stack<pair<int, int>> stk;
        stk.push(make_pair(i, j));
        while (!stk.empty()) {
            int i = stk.top().first;
            int j = stk.top().second;
            stk.pop();
            for (auto index : { make_pair(i-1, j), make_pair(i+1, j), make_pair(i, j-1), make_pair(i, j+1)})
                if (isValid(grid, index.first, index.second)) {
                    grid[index.first][index.second] = '0';
                    stk.push(index);
                }
        }
    }

    // BFS with a queue
    void BFS(vector<vector<char>> &grid, int r, int c) {
        grid[r][c] = '0';
        queue<pair<int, int>> Q({{r, c}});
        while (!Q.empty()) {
            int i = Q.front().first;
            int j = Q.front().second;
            Q.pop();
            for (auto index : { make_pair(i-1, j), make_pair(i+1, j), make_pair(i, j-1), make_pair(i, j+1)})
                if (isValid(grid, index.first, index.second)) {
                    grid[index.first][index.second] = '0';
                    Q.push(index);
                }
        }
    }
};

int main(int argc, char **argv) {
    int n;
    while (cin >> n && cin.get()) {
        vector<vector<char>> grid;
        string line;
        while (n-- > 0 && getline(cin, line)) 
            grid.push_back(vector<char>(line.begin(), line.end()));
        cout << Solution().numIslands(grid) << endl;
    }
    return 0;
}
