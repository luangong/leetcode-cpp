/*
Rotate Image

You are given an n x n 2D matrix representing an image.  Rotate the image by
90 degrees (clockwise).

Follow up: Could you do this in-place?

Tags: Array
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate2(vector<vector<int>> &matrix) {
        const auto n = matrix.size();
        vector<vector<int>> clone(matrix);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matrix[i][j] = clone[n-j-1][i];
    }

    // Rotate in-place
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int layer = 0; layer < n/2; ++layer) {
            int first = layer;
            int last = n-layer-1;
            for (int i = first; i < last; ++i) {
                int offset = i - first;
                int tmp = matrix[first][i];
                matrix[first][i] = matrix[last-offset][first];
                matrix[last-offset][first] = matrix[last][last-offset];
                matrix[last][last-offset] = matrix[i][last];
                matrix[i][last] = tmp;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        // 先沿着副对角线翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n-i; ++j)
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        // 再沿着横轴翻转
        for (int i = 0; i < n/2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-i-1][j]);
    }

    void rotate(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        // 先沿着横轴翻转
        for (int i = 0; i < n/2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-i-1][j]);
        // 再沿着主对角线翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }

    void rotate(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        // 先沿着主对角线翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
        // 再沿着纵轴翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n/2; ++j)
                swap(matrix[i][j], matrix[i][n-j-1]);
    }

    void rotate(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        // 先沿着纵轴翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n/2; ++j)
                swap(matrix[i][j], matrix[i][n-j-1]);
        // 再沿着副对角线翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n-i; ++j)
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
    }
};

int main(int argc, char **argv) {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> matrix[i][j];
        Solution().rotate(matrix);
        for (const auto &row : matrix) {
            copy(row.begin(), row.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
    }
    return 0;
}
