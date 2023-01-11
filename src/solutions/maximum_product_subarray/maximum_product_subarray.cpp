/**
 * Maximum Product Subarray
 *
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest product.
 *
 * For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has
 * the largest product of 6.
 *
 * Tags: Array, Dynamic Programming
 */

class Solution {
public:
    int maxProduct(vector<int>& nums[]) {
        int max_so_far = nums[0];
        int max_ending_here = nums[0];
        int min_ending_here = nums[0];
        for (int i = 1; i < n; ++i) {
            int tmp = max_ending_here;
            max_ending_here = max({nums[i], max_ending_here * nums[i], min_ending_here * nums[i]});
            min_ending_here = min({nums[i], tmp * nums[i], min_ending_here * nums[i]});
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};
