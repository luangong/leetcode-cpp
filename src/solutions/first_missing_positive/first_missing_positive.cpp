/*
 * First Missing Positive
 *
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 * Tags: Array
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; ++i)
            if (A[i] <= 0)
                A[i] = n + 2;
        for (int i = 0; i < n; ++i) {
            if (1 <= abs(A[i]) && abs(A[i]) <= n) {
                int index = abs(A[i]) - 1;
                A[index] = -abs(A[index]);
            }
        }
        for (int i = 0; i < n; ++i)
            if (A[i] > 0)
                return i+1;
        return n+1;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> A((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().firstMissingPositive(&A[0], A.size()) << endl;
    }
    return 0;
}
