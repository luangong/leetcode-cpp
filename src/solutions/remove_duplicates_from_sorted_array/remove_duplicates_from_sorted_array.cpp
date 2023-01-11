/*
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element
appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with
constant memory.

For example, given input array A = [1,1,2], your function should return
length = 2, and A is now [1,2].
*/

class Solution {
public:
    // 方法一：调用 STL 函数
    int removeDuplicates(int A[], int n) {
        return unique(A, A + n) - A;
    }

    // 方法二：自己写 :-)
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int i = 0;
        for (int j = 1; j < n; ++j)
            if (A[j] != A[i])
                A[++i] = A[j];
        return i + 1;
    }
};
