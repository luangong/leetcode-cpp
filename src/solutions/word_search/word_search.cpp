/*
 * Word Search
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where
 * "adjacent" cells are those horizontally or vertically neighboring.  The same
 * letter cell may not be used more than once.
 *
 * For example, given board
 *
 *    [
 *      ["ABCE"],
 *      ["SFCS"],
 *      ["ADEE"]
 *    ]
 *
 * word = "ABCCED", -> returns true,
 * word = "SEE",    -> returns true,
 * word = "ABCB",   -> returns false.
 *
 * Tags: Array, Backtracking
 */

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, const string& word) {
        auto m = board.size();
        auto n = board[0].size();
        vector<vector<bool>> explored(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (backtrack(board, i, j, word, 0, explored))
                    return true;
        return false;
    }

    /*
     * 本题只能用递归版的回溯法解决，不能用 BFS 或显式栈的回溯法。因为后两种方法
     * 会在每一层同时扩展多个节点并把这些节点加入到 explored 集合中，这会干扰后
     * 面的判断，导致程序错误地返回 false
     */
    bool backtrack(const vector<vector<char>>& board, int i, int j,
            const string& word, int k, vector<vector<bool>>& explored) {
        // 如果已经匹配了全部字符，则成功返回
        if (k == word.size())
            return true;
        // 判断下标是否在正常范围内
        if (i < 0 || board.size() <= i || j < 0 || board[0].size() <= j)
            return false;
        // 判断当前元素是否访问过以及当前字符是否等于 word 中相应的字符
        if (explored[i][j] || board[i][j] != word[k])
            return false;
        explored[i][j] = true;
        for (int row : { i-1, i+1 })
            if (backtrack(board, row, j, word, k+1, explored))
                return true;
        for (int col : { j-1, j+1 })
            if (backtrack(board, i, col, word, k+1, explored))
                return true;
        explored[i][j] = false;
        return false;
    }
};

int main(int argc, char **argv) {
    int N;
    while (cin >> N) {
        string word;
        getline(cin, word);
        vector<vector<char>> board(N);
        for (int i = 0; i < N; ++i) {
            string line;
            getline(cin, line);
            board[i] = vector<char>(line.begin(), line.end());
            copy(board[i].begin(), board[i].end(), ostream_iterator<char>(cout, ""));
            cout << endl;
        }
        cout << Solution().exist(board, word) << endl;
    }
    return 0;
}
