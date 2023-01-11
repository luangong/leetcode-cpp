/**
 * 4Sum
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S
 * such that a + b + c + d = target? Find all unique quadruplets in the array
 * which gives the sum of target.
 *
 * Note:
 *
 *    - Elements in a quadruplet (a,b,c,d) must be in non-descending order.
 *      (i.e., a <= b <= c <= d)
 *
 *    - The solution set must not contain duplicate quadruplets.
 *      For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *      A solution set is:
 *
 *         (-1,  0, 0, 1)
 *         (-2, -1, 1, 2)
 *         (-2,  0, 0, 2)
 *
 * Tags: Array, Hash Table, Two Pointers
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int>> result;
        if (num.size() < 4) return result;
        sort(num.begin(), num.end());
        // 对于 k-sum 问题，先排序，然后做 k-2 次循环，在循环的最内层设两个指针
        // L, R 同时往中间走，遇到 k 个数相加的和等于给定的值就表示找到了
        // 一个解。这样总的时间复杂度是 max(O(nlgn), O(n^{k-1}))
        for (int i = 0; i < num.size()-3; ++i) {
            for (int j = i+1; j < num.size()-2; ++j) {
                int L = j+1, R = num.size()-1;
                while (L < R) {
                    if (num[i] + num[j] + num[L] + num[R] < target)
                        ++L;
                    else if (num[i] + num[j] + num[L] + num[R] > target)
                        --R;
                    else {
                        result.push_back({num[i], num[j], num[L], num[R]});
                        ++L; --R;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }

    vector<vector<int>> fourSum2(vector<int>& num, int target) {
        vector<vector<int>> result;
        if (num.size() < 4) return result;
        sort(num.begin(), num.end());
        unordered_multimap<int, pair<int,int>> pair_sum;
        for (int i = 0; i < num.size()-1; ++i)
            for (int j = i+1; j < num.size(); ++j)
                pair_sum.insert(make_pair(num[i] + num[j], make_pair(i, j)));
        // Worst-case O(n^4)
        for (int i = 0; i < num.size()-3; ++i) {
            for (int j = i+1; j < num.size()-2; ++j) {
                auto rest_range = pair_sum.equal_range(target - num[i] - num[j]);
                for (auto iter = rest_range.first; iter != rest_range.second; ++iter) {
                    cout << i << ", " << j << ", ";
                    cout << iter->second.first << ", " << iter->second.second << endl;
                    if (iter->second.first > j)
                        result.push_back({num[i], num[j], num[iter->second.first], num[iter->second.second]});
                }
            }
        }
        /*
        for (auto iter = pair_sum.begin(); iter != pair_sum.end(); ++iter) {
            int rest = target - iter->first;
            auto range = pair_sum.equal_range(rest);
            for (auto iter2 = range.first; iter2 != range.second; ++iter2) {
                auto i = iter->second.first;
                auto j = iter->second.second;
                auto k = iter2->second.first;
                auto L = iter2->second.second;
                if (i != k && i != L && j != k && j != L) {
                    vector<int> sln = {num[h], num[i], num[j], num[k]};
                    sort(sln.begin(), sln.end());
                    result.push_back(sln);
                }
            }
        }
        */
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

int main(int argc, char **argv) {
    vector<int> num{0,0,0,0};
    Solution().fourSum2(num, 0);
    return 0;
}
