/**
 * N-Queens II
 *
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 *
 * Tags: Backtracking
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> sln(n);
        int numSolutions = 0;
        backtrack(sln, 0, numSolutions);
        return numSolutions;
    }

    void backtrack(vector<int>& sln, int k, int& numSolutions) {
        if (k == sln.size()) {
            ++numSolutions;
            return;
        }
        for (int i = 0; i < sln.size(); ++i) {
            if (isValidPos(sln, k, i)) {
                sln[k] = i;
                backtrack(sln, k+1, numSolutions);
            }
        }
    }

    bool isValidPos(const vector<int>& sln, int k, int i) {
        for (int j = 0; j < k; ++j)
            if (i == sln[j] || abs(sln[j]-i) == k-j)
                return false;
        return true;
    }
};

int main(int argc, char **argv) {
    int n;
    while (cin >> n) {
        Solution sln;
        cout << sln.totalNQueens(n) << endl;
    }
    return 0;
}
