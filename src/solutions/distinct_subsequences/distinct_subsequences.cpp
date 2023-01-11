/**
 * Distinct Subsequences
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 *
 * Tags: Dynamic Programming, String
 */
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 用 f[i,j] 表示 S[1..i] 中不同的子串 T[1..j] 的个数，考虑字符 S[i] 和
     * T[j]，如果 S[i] != T[j]，则问题转化为求字符串 S[1..i-1] 中不同的子串
     * T[1..j-1] 的个数，即 f[i,j] = f[i-1,j]；如果 S[i] == T[j]，那么 T[j]
     * 可以与 S[i] 匹配，也可以选择不与 S[i] 匹配，总的不同子串的个数为两者
     * 之和，即 f[i,j] = f[i-1,j] + f[i-1,j-1]。
     *
     * 原问题的解为整个字符串 S 中不同的子字符串 T 的个数，即 f[n,m]
     *
     * 若 S 为空字符串，则 f[0,j] = 0，若 T 为空字符串，则 f[i,0] = 1，
     * 若 S 和 T 都为空字符串，则 f[0,0] = 1
     */
    int numDistinct2(string S, string T) {
        vector<vector<int>> f(S.size() + 1, vector<int>(T.size() + 1));
        for (int j = 0; j <= T.size(); ++j)
            f[0][j] = 0;
        for (int i = 0; i <= S.size(); ++i) {
            f[i][0] = 1;
            for (int j = 1; j <= T.size(); ++j) {
                if (S[i-1] != T[j-1])
                    f[i][j] = f[i-1][j];
                else
                    f[i][j] = f[i-1][j] + f[i-1][j-1];
            }
        }
        copy(f.back().begin(), f.back().end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        return f.back().back();
    }

    // 用一维滚动数组优化
    int numDistinct(const string& S, const string& T) {
        vector<int> f(T.size()+1, 0);
        f[0] = 1;
        for (int i = 1; i <= S.size(); ++i) {
            // 注意因为用了一维滚动数组，为了在计算 f[j] 时可以使用上次
            // 的 f[j-1] 的值，内层循环的计算顺序要从右到左
            for (int j = T.size(); j >= 1; --j) {
                if (S[i-1] == T[j-1])
                    f[j] = f[j] + f[j-1];
                // else
                //     f[j] = f[j];
            }
        }
        return f.back();
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string S, T;
    while (cin >> S >> T)
        cout << sln.numDistinct(S, T) << endl;
    return 0;
}
