/**
 * Permutations II
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * For example, [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 *
 * Tags: Backtracking
 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        do {
            permutations.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return permutations;
    }
};
