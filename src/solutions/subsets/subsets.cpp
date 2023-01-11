/**
 * Subsets
 *
 * Given a set of distinct integers, S, return all possible subsets.
 *
 * Note:
 *
 *   - Elements in a subset must be in non-descending order.
 *   - The solution set must not contain duplicate subsets.
 *
 * For example, if S = [1, 2, 3], a solution is:
 *
 *   [
 *     [3],
 *     [1],
 *     [2],
 *     [1,2,3],
 *     [1,3],
 *     [2,3],
 *     [1,2],
 *     []
 *   ]
 *
 * Tags: Array, Backtracking, Bit Manipulation
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& numbers) {
        vector<vector<int>> result;
        vector<int> sln;
        sort(numbers.begin(), numbers.end());
        backtrack(numbers, sln, 0, result);
        return result;
    }

    void backtrack(const vector<int>& numbers, vector<int>& sln, int start,
                    vector<vector<int>>& result) {
        result.push_back(sln);
        for (int i = start; i < numbers.size(); ++i) {
            sln.push_back(numbers[i]);
            backtrack(numbers, sln, i+1, result);
            sln.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& numbers) {
        numbers.sort();
        vector<vector<int>> result;
        for (unsigned x = 0; x < (1 << numbers.size()); ++x) {
            vector<int> subset;
            for (int i = 0; i < 32; ++i)
                if (x & (1 << i))
                    subset.push_back(numbers[i]);
            result.push_back(subset);
        }
        return result;
    }
};
