/**
 * Permutation
 *
 * Given a collection of numbers, return all possible permutations.
 *
 * For example, [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 * Tags: Backtracking
 */

class Solution {
public:
    // 方法一：从起始排列开始不断调用 std::next_permutation 直到返回 false
    vector<vector<int>> permute(const vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }

    // 方法二：回溯法，每次选择一个未选择的数添加到解向量末尾
    vector<vector<int>> permute(const vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> solution;
        vector<bool> selected(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, solution, selected, result);
        return result;
    }

    void backtrack(const vector<int>& nums, vector<int>& permutation,
                   vector<bool>& selected, vector<vector<int>>& result) {
        if (permutation.size() == nums.size()) {
            result.push_back(solution);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (selected[i]) continue;
            selected[i] = true;
            permutation.push_back(nums[i]);
            backtrack(nums, permutation, selected, result);
            permutation.pop_back();
            selected[i] = false;
        }
    }
};

int main(int argc, char **argv) {
    Solution sln;
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            nums[i] = i + 1;
        vector<vector<int>> result = permute(nums);
        for (int i = 0; i < result.size(); ++i) {
            copy(result[i].begin(), result[i].end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
    }
    return 0;
}
