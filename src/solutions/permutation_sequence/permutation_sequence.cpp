/**
 * Permutation Sequence
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order, we get the
 * following sequence (i.e., for n = 3):
 *
 *    "123"
 *    "132"
 *    "213"
 *    "231"
 *    "312"
 *    "321"
 *
 * Given n and k, return the k-th permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 *
 * Tags: Backtracking, Math
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        for (int i = 0; i < n; ++i)
            s[i] = i + '0';
        int factorial = 1;
        for (int i = 2; i <= n; ++i)
            factorial *= i;
        /* 如果 k 小于或等于 n! / 2，则以字典序上升的顺序执行 k-1 次
         * next_permutation 操作，否则以字典序下降的顺序做 n!-k+1 次
         * prev_permutation 操作，以上两种操作的效果是一样的，但可以避免
         * k 过大时超时
         */
        if (k <= factorial / 2)
            for (int i = 0; i < k-1; ++i)
                next_permutation(s.begin(), s.end());
        else
            for (int i = 0; i < factorial-k+1; ++i)
                prev_permutation(s.begin(), s.end());
        return s;
    }

    /*
     * 用 1 到 9! 来标志序号。那么我要查找的是编号 297192。假设第一位是 a，
     * 不论 a 是什么数，axxxxxxxx 一共有 8! 种选择。297192 / 8! = 7，余 14952，
     * 所以第一位是 1-9 中的第 8 个数，也就是 8。14952 / 7! = 2，余 4872，所以
     * 第二位是 3。4872 / 6! = 6，余 552，所以是第三位是 1245679 这七个数中的
     * 第 7 个，也就是 9。552 / 5! = 4，余 72，所以是 124567 中的第 5 个，也就是
     * 6。72 / 4! = 2，余 24，所以是 4。这时候就不用算了，因为24 = 4!，而剩下的
     * 数就是 1257 这 4 个，他们组成的排列的第 24 个必然是 7521。
     *
     * 因为以 1 开头的 permutation 有 8! 个，以 2 开头的 permutation 也有 8! 个，
     * ...，以 9 开头的 permutation 有 8! 个，所以我们先把 k / 8!，得到
     * permutation 的第一个数，然后令 k = k % 8!，就得到了去掉了那个数之后的剩余
     * 8 个数的 permutation sequence，然后递归地计算下去...
     */
    string getPermutation2(int n, int k) {
        string str;
        vector<int> factorial(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            str += i + '0';
            factorial[i] = factorial[i-1] * i;
        }
        string perm;
        --k;    // convert to 0-based index
        for (int i = n-1; i >= 0; --i) {
            int quotient = k / factorial[i];
            k %= factorial[i];
            perm += str[quotient];
            str.erase(quotient, 1);
        }
        return perm;
    }
};

int main(int argc, char **argv) {
    int n, k;
    while (cin >> n >> k)
        cout << Solution().getPermutation2(n, k) << endl;
    return 0;
}
