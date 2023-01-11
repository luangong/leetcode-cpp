/**
 * Combination Sum II
 *
 * Given a collection of candidate numbers (C) and a target number (T), find all
 * unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 *
 *    - All numbers (including target) will be positive integers.
 *    - Elements in a combination (a_1, a_2, ..., a_k) must be in non-descending
 *      order. (i.e., a_1 <= a_2 <= ... <= a_k).
 *    - The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 *
 *    [1, 7]
 *    [1, 2, 5]
 *    [2, 6]
 *    [1, 1, 6]
 *
 * Tags: Array, Backtracking
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& num, int target) {
        vector<vector<int>> result;
        vector<int> sln;
        sort(num.begin(), num.end());
        backtrack(num, target, sln, 0, result);
        return result;
    }

    void backtrack(const vector<int>& num, int rest, vector<int>& sln, int start, vector<vector<int>>& result) {
        if (rest == 0) {
            result.push_back(sln);
            return;
        }
        for (int i = start; i < num.size() && num[i] <= rest; ++i) {
            if (i == start || num[i] != num[i-1]) {
                sln.push_back(num[i]);
                backtrack(num, rest - num[i], sln, i+1, result);
                sln.pop_back();
            }
        }
    }
};
