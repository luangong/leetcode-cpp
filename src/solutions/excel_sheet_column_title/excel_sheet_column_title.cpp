/**
 * Excel Sheet Column Title
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 *
 * For example:
 *
 *    1 -> A
 *    2 -> B
 *    3 -> C
 *
 *      ...
 *
 *    26 -> Z
 *    27 -> AA
 *    28 -> AB
 *
 * Credits: Special thanks to @ifanchu for adding this problem and creating all
 * test cases.
 *
 * Tags: Math
 */

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n != 0) {
            result += 'A' + (n-1) % 26;
            n = (n-1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string convertToTitle(int n) {
        if (n == 0)
            return "";
        else
            return convertToTitle((n-1) / 26) + char('A' + (n-1) % 26);
    }
};
