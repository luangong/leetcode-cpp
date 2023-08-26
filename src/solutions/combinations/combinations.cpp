/**
 * Combinations
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1...n.
 *
 * For example, if n = 4 and k = 2, a solution is:
 *
 *   [
 *     [2, 4],
 *     [3, 4],
 *     [2, 3],
 *     [1, 2],
 *     [1, 3],
 *     [1, 4],
 *   ]
 *
 * Tags: Backtracking
 */

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> sln;
    backtrack(n, sln, 1, result);
    return result;
  }

  void backtrack(vector<int>& sln, int n, int k, int start, vector<vector<int>>& result) {
    if (sln.size() == k) {
      result.push_back(sln);
    } else {
      // The candidates are the numbers in the range [start, n]
      for (int i = start; i <= n; ++i) {
        sln.push_back(i);
        backtrack(sln, n, k, i+1, result);
        sln.pop_back();
      }
    }
  }
};
