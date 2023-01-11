/**
 * Combination Sum
 *
 * Given a set of candidate numbers (C) and a target number (T), find all unique
 * combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 *
 *    - All numbers (including target) will be positive integers.
 *    - Elements in a combination (a_1, a_2, ..., a_k) must be in non-descending
 *      order. (ie, a_1 <= a_2 <= ... <= a_k).
 *    - The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 2,3,6,7 and target 7, A solution set is:
 *
 *    [7]
 *    [2, 2, 3]
 *
 * Tags: Array, Backtracking
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& num, int target) {
        vector<vector<int>> result;
        vector<int> sln;
        sort(num.begin(), num.end());
        backtrack(num, target, sln, 0, result);
        return result;
    }

    void backtrack(const vector<int>& num, int rest,
            vector<int>& sln, int start, vector<vector<int>>& result) {
        if (rest == 0) {
            result.push_back(sln);
            return;
        }
        for (int i = start; i < num.size() && num[i] <= rest; ++i) {
            // 由于每个数字都可以选择无限次，所以原数组是否包含重复数字
            // 无关紧要，不过这里还是在同一层避免选择相同的数字
            if (i == start || num[i] != num[i-1]) {
                sln.push_back(num[i]);
                backtrack(num, rest - num[i], sln, i, result);
                sln.pop_back();
            }
        }
    }
};
