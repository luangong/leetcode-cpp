/**
 * Excel Sheet Column Number
 *
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 *
 *    A -> 1
 *    B -> 2
 *    C -> 3
 *
 *      ...
 *
 *    Z -> 26
 *    AA -> 27
 *    AB -> 28
 *
 * Credits: Special thanks to @ts for adding this problem and creating all test
 * cases.
 *
 * Tags: Math
 */


class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for (char c: s)
            num = num * 26 + c - 'A' + 1;
        return num;
    }

    int titleToNumber(string s) {
        if (s.empty())
            return 0;
        else
            return titleToNumber(s.substr(0, s.size()-1) * 26 + s.back() - 'A' + 1;
    }
};
