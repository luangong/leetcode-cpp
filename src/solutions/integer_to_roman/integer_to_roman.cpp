/**
 * Integer to Roman
 *
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * Tags: Math, String
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const char *thousands[]   = { "", "M", "MM", "MMM" };
        const char *hundreds[]    = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        const char *tens[]        = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        const char *individuals[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
        return string() + thousands[num / 1000]
                        + hundreds[num % 1000 / 100]
                        + tens[num % 100 / 10]
                        + individuals[num % 10];
    }
};

int main(int arg, char **argv) {
    int num;
    while (cin >> num)
        cout << Solution().intToRoman(num) << endl;
    return 0;
}
