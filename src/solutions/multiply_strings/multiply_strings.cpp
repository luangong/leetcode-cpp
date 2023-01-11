/**
 * Mutiply Strings
 *
 * Given two numbers represented as strings, return multiplication of the
 * numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *
 * Tag: Math, String
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        // 逆转两个字符串，使得低位在低地址，便于之后的处理
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // 先把各位相乘并保存起来，注意偏移量
        vector<int> product(num1.size() + num2.size(), 0);
        for (int i = 0; i < num2.size(); ++i)
            for (int j = 0; j < num1.size(); ++j)
                product[i+j] += (num2[i] - '0') * (num1[j] - '0');

        // 然后统一处理进位
        int carry = 0;
        for (int i = 0; i < product.size(); ++i) {
            product[i] += carry;
            carry = product[i] / 10;
            product[i] %= 10;
        }

        // 把用 int 数组表示的结果转换为字符串，同时逆序并除去前导的 0
        string result;

        auto last_digit = find_if(product.rbegin(), product.rend(),
                [](int x){ return x != 0; });
        transform(last_digit, product.rend(),
                back_inserter(result), bind2nd(plus<int>(), '0'));
        return result;

        // transform(product.rbegin(), product.rend(),
        //         back_inserter(result), bind2nd(plus<int>(), '0'));
        // 返回前跳过前面连续的 0
        // return result.substr(result.find_first_of("123456789"));
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string num1, num2;
    while (cin >> num1 >> num2)
        cout << sln.multiply(num1, num2) << endl;
    return 0;
}
