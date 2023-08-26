/**
 * Remove Duplicates from Sorted Array II
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example, given sorted array A = [1,1,1,2,2,3], your function should
 * return length = 5, and A is now [1,1,2,2,3].
 *
 * Tags: Array, Two Pointers
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) return n;
        int occur = 1;
        int i = 0;
        for (int j = 1; j < n; ++j) {
            if (A[i] != A[j]) {
                occur = 1;
                A[++i] = A[j];
            } else if (occur < 2) {
                ++occur;
                A[++i] = A[j];
            }
        }
        return i + 1;
    }
};
