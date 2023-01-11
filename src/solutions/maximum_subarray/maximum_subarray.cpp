/**
 * Maximum Subarray
 *
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous subarray
 * [4,−1,2,1] has the largest sum = 6.
 *
 * More practice: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 * Tags: Divide and Conquer, Array, Dynamic Programming
 */

#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ending_here = nums[0];
        int max_so_far = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            max_ending_here = max(nums[i], nums[i] + max_ending_here);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};
