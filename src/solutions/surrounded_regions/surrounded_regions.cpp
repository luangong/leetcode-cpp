/**
 * Surrounded Regions
 *
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by
 * 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 * For example,
 *
 *    X X X X
 *    X O O X
 *    X X O X
 *    X O X X
 *
 * After running your function, the board should be:
 *
 *    X X X X
 *    X X X X
 *    X X X X
 *    X O X X
 *
 * Tags: Breadth-first Search
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * First traverse the four borders of the board, replace all 'O's that are
     * connected to the 'O's at the border with a temporary character
     * (e.g., '#').
     *
     * Then traverse the entire board, if an 'O' is found, it must be an
     * interior element, so we change it to 'X', otherwise if a '#' is found,
     * then it should be the 'O' character before, so we just restore it to 'O'.
     *
     * Both DFS and BFS can be used to visit connected components.
     */
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            BFS(board, i, 0);           // left-most column
            BFS(board, i, m-1);         // right-most column
        }
        for (int j = 1; j < m-1; ++j) {
            BFS(board, 0, j);           // top row
            BFS(board, n-1, j);         // bottom row
        }
        // Traverse the entire board, changing O's to X's and #'s to O's
        for (auto& row : board) {
            for (char& c : row)
                if (c == 'O') c = 'X';
                else if (c == '#') c = 'O';
        }
    }

    // DFS with recursion.  May cause stack overflow in case of large data.
    void DFS(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') return;
        board[i][j] = '#';
        if (i-1 >= 0)
            DFS(board, i-1, j);
        if (i+1 < board.size())
            DFS(board, i+1, j);
        if (j-1 >= 0)
            DFS(board, i, j-1);
        if (j+1 < board[0].size())
            DFS(board, i, j+1);
    }

    // Use explicit stack to avoid stack overflow.
    void DFS(vector<vector<char>>& board, int row, int col) {
        stack<pair<int, int>> stk;
        stk.push(make_pair(row, col));
        while (!stk.empty()) {
            int row = stk.top().first;
            int col = stk.top().second;
            stk.pop();
            if (board[row][col] != 'O')
                continue;
            board[row][col] = '#';
            if (row-1 >= 0)
                stk.push(make_pair(row-1, col));
            if (row+1 < board.size())
                stk.push(make_pair(row+1, col));
            if (col-1 >= 0)
                stk.push(make_pair(row, col-1));
            if (col+1 < board[0].size())
                stk.push(make_pair(row, col+1));
        }
    }

    // BFS with a queue
    void BFS(vector<vector<char>>& board, int row, int col) {
        queue<pair<int, int>> Q;
        Q.push(make_pair(row, col));
        while (!Q.empty()) {
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();
            if (board[row][col] != 'O')
                continue;
            board[row][col] = '#';
            if (row-1 >= 0)
                Q.push(make_pair(row-1, col));
            if (row+1 < board.size())
                Q.push(make_pair(row+1, col));
            if (col-1 >= 0)
                Q.push(make_pair(row, col-1));
            if (col+1 < board[0].size())
                Q.push(make_pair(row, col+1));
        }
    }
};

int main(int argc, char **argv) {
    Solution sln;
    int n;
    while (cin >> n) {
        cin.get();
        vector<vector<char>> board;
        string line;
        while (n-- > 0) {
            getline(cin, line);
            board.push_back(vector<char>(line.begin(), line.end()));
        }
        sln.solve(board);
        for (const auto& vec : board) {
            copy(vec.begin(), vec.end(), ostream_iterator<char>(cout, " "));
            cout << endl;
        }
    }
    return 0;
}
