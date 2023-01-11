/**
 * 3Sum Closest
 *
 * Given an array S of n integers, find three integers in S such that the sum is
 * closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 * Tags: Array, Two Pointers
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>&nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = target + numeric_limits<int>::max();
        for (int i = 0; i < nums.size()-2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(closest_sum - target))
                    closest_sum = sum;
                if (sum > target) --k;
                else if (sum < target) ++j;
                else return target;
            }
        }
        return closest_sum;
    }
};
