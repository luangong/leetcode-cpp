/*
 * Jump Game
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 *
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 *
 * Tags: Array, Greedy
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
    bool canJump(int A[], int n) {
        int i = 0;
        // max_index 表示从起始下标 0 出发，所能到达的最远的下标
        int max_index = 0;
        // 只要当前下标在有效范围内，就不断地向前走，扩展所能
        // 到达的最远距离
        while (i <= max_index) {
            max_index = max(max_index, i + A[i]);
            // 如果最远距离达到或超出数组最后一个元素，则返回 true
            if (max_index >= n-1)
                return true;
            ++i;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> vec((istream_iterator<int>(iss)),
                istream_iterator<int>());
        cout << Solution().canJump(&vec[0], vec.size()) << endl;
    }
    return 0;
}
