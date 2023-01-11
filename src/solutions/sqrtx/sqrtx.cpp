/**
 * Sqrt(x)
 *
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 *
 * Tags: Math, Divide and Conqure
 */
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    // 二分查找法，一阶收敛速度，较慢
    int sqrt(int x) {
        if (x <= 1) return x;
        int lower = 0, upper = x;
        while (lower + 1 < upper) {
            int mid = (lower + upper) / 2.0;
            if (x / mid < mid)
                upper = mid;
            else if (x / mid > mid)
                lower = mid;
            else
                return mid;
        }
        return lower;
    }

    // 牛顿迭代法，二阶收敛速度，较快
    int sqrt_newton(int x) {
        double y = x / 2.0;         // initialize y
        while (fabs(y*y - x) > 1e-5)
            y = (y + x/y) / 2.0;
        return int(y);
    }
};

int main(int argc, char **argv) {
    Solution sln;
    int x;
    while (cin >> x)
        cout << "sqrt ( " << x << " ) = " << sln.sqrt(x) << endl;
    return 0;
}
