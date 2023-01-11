/*
 * Pascal's Triangle
 *
 * Given an integer N, generate the first N rows of Pascal's triangle.
 *
 * For example, given N = 5,
 * Return
 *
 *   [
 *     [1],
 *     [1, 1],
 *     [1, 2, 1],
 *     [1, 3, 3, 1],
 *     [1, 4, 6, 4, 1]
 *   ]
 *
 * Tags: Array
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int N) {
        vector<vector<int>> triangle;
        for (int i = 0; i < N; ++i) {
            triangle.push_back(vector<int>(i+1, 1));
            for (int j = 1; j < i; ++j)
                triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
        }
        return triangle;
    }
};

int main(int argc, char **argv) {
    int N;
    while (cin >> N) {
        const auto& triangle = Solution().generate(N);
        for (const auto& row : triangle) {
            copy(row.begin(), row.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
    }
    return 0;
}
