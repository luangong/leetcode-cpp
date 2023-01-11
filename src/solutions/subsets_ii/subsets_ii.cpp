/**
 * Subsets II
 *
 * Given a collection of integers that might contain duplicates, S, return all
 * possible subsets.
 *
 * Note:
 *
 *    - Elements in a subset must be in non-descending order.
 *    - The solution set must not contain duplicate subsets.
 *
 * For example, if S = [1,2,2], a solution is:
 *
 *    [
 *      [2],
 *      [1],
 *      [1,2,2],
 *      [2,2],
 *      [1,2],
 *      []
 *    ]
 *
 * Tags: Array, Backtracking
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 方法一：先按常规的子集生成方法做，最后再对全部解向量的集合进行去重。
     * 时间复杂度为 O(2^n log(2^n)) = O(n 2^n)
     */
    vector<vector<int>> subsetsWithDup(vector<int>& numbers) {
        vector<vector<int>> result;
        sort(numbers.begin(), numbers.end());
        for (int x = 0; x < (1 << numbers.size()); ++x) {
            vector<int> subset;
            for (int i = 0; i < numbers.size(); ++i)
                if (x & (1 << i))
                    subset.push_back(numbers[i]);
            result.push_back(subset);
        }
        sort(result.begin(), result.end());
        result.resize(unique(result.begin(), result.end()) - result.end());
        return result;
    }

    /**
     * 方法二：先对原数组进行排序，然后在同一层递归的时候只从余下的元素
     * 中选择不重复的值。时间复杂度为 O(2^n)
     */
    vector<vector<int>> subsetsWithDup2(vector<int>& numbers) {
        vector<vector<int>> result;
        sort(numbers.begin(), numbers.end());
        vector<int> subset;
        backtrack(numbers, subset, 0, result);
        return result;
    }

    void backtrack(vector<int>& numbers, vector<int>& subset, int start, vector<vector<int>>& result) {
        result.push_back(subset);
        // 同一层递归只从余下的元素中选择不同的值，由于事先对原数组进行了排序，
        // 所以只有当前要选择的元素跟上次选择的不一样时才把它追加到解向量末尾
        for (int i = start; i < numbers.size(); ++i) {
            if (i == start || numbers[i] != numbers[i-1]) {
                subset.push_back(numbers[i]);
                backtrack(numbers, subset, i+1, result);
                subset.pop_back();
            }
        }
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> numbers((istream_iterator<int>(iss)), istream_iterator<int>());
        auto result = Solution().subsetsWithDup(numbers);
        for (auto& subset : result) {
            copy(subset.begin(), subset.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
    }
    return 0;
}
