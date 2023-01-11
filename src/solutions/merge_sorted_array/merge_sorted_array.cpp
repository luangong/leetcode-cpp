/*
 * Merge Sorted Array
 *
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note: You may assume that A has enough space to hold additional elements from
 * B.  The number of elements initialized in A and B are m and n respectively.
 *
 * Tags: Array, Two Pointers
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
    void merge(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (i >= 0 && j >= 0) {
            A[k--] = (A[i] > B[j] ? A[i--] : B[j--]);
            // if (A[i] > B[j])
            //     A[k--] = A[i--];
            // else
            //     A[k--] = B[j--];
        }
        while (j >= 0) A[k--] = B[j--];
    }
};

int main(int argc, char **argv) {
    string line1, line2;
    while (getline(cin, line1) && getline(cin, line2)) {
        istringstream iss(line1);
        vector<int> A((istream_iterator<int>(iss)), istream_iterator<int>());
        iss.clear();
        iss.str(line2);
        vector<int> B((istream_iterator<int>(iss)), istream_iterator<int>());
        // Enlarge A to hold B
        A.resize(A.size()+B.size());
        Solution().merge(&A[0], A.size()-B.size(), &B[0], B.size());
        copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}
