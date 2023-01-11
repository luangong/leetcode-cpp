/*
Pascal's Triangle II

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note: Could you optimize your algorithm to use only O(k) extra space?

Tags: Array
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: rowIndex is 0-based index
        vector<int> row(rowIndex + 1, 1);
        for (int i = 0; i < rowIndex + 1; ++i)
            for (int j = i-1; j >= 1; --j)
                row[j] = row[j] + row[j-1]
        return row;
    }
};
