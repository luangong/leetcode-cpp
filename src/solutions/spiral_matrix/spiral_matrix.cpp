/*
Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of
the matrix in spiral order.

For example, given the following matrix:

  [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
  ]

You should return [1,2,3,6,9,8,7,4,5].

Tags: Array
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty())
            return result;
        ssize_t first_col = 0, last_col = matrix[0].size()-1;
        ssize_t first_row = 0, last_row = matrix.size()-1;
        while (true) {
            // 从左到右 >
            for (ssize_t j = first_col; j <= last_col; ++j)
                result.push_back(matrix[first_row][j]);
            if (++first_row > last_row)
                break;
            // 从上到下 V
            for (ssize_t i = first_row; i <= last_row; ++i)
                result.push_back(matrix[i][last_col]);
            if (first_col > --last_col)
                break;
            // 从右到左 <
            // 注意第一次从右到左循环时 first_col 为 0，为避免死循环，
            // 这里使用带符号的 ssize_t 作为下标
            for (ssize_t j = last_col; j >= first_col; --j)
                result.push_back(matrix[last_row][j]);
            if (first_row > --last_row)
                break;
            // 从下到上 ^
            for (ssize_t i = last_row; i >= first_row; --i)
                result.push_back(matrix[i][first_col]);
            if (++first_col > last_col)
                break;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    string line;
    vector<vector<int>> matrix;
    while (getline(cin, line)) {
        matrix.push_back(vector<int>());
        istringstream iss(line);
        copy(istream_iterator<int>(iss), istream_iterator<int>(),
                back_inserter(matrix.back()));
    }
    vector<int> result = Solution().spiralOrder(matrix);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
