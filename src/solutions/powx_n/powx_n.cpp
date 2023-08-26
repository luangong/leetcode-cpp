/*
 * Pow(x, n)
 *
 * Implement pow(x, n).
 *
 * Tags: Math, Binary Search
 */

#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        // Calling pow(x, -n) when n == INT_MIN will result in integer underflow
        double half = pow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else if (n > 0)
            return half * half * x;
        else
            return half * half / x;
    }

    double myPow2(double x, int n) {
        unsigned m = abs(n);
        double result = 1.0;
        while (m != 0) {
            if (m % 2 == 1)
                result *= x;
            x *= x;
            m /= 2;
        }
        return n >= 0 ? result : 1.0 / result;
    }

    double myPow3(double x, int n) {
        unsigned m = abs(n);
        double result = 1.0;
        for (int i = numeric_limits<int>::digits - 1; i >= 0; --i) {
            result *= result;
            if (m & (1 << i))
                result *= x;
        }
        return n >= 0 ? result : (1.0 / result);
    }
};

int main(int argc, char **argv) {
    double x;
    int n;
    while (cin >> x >> n)
        cout << Solution().pow1(x, n) << endl;
    return 0;
}
