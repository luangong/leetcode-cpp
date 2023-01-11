/**
 * Longest Consecutive Sequence
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * For example, given [100, 4, 200, 1, 3, 2], the longest consecutive elements
 * sequence is [1, 2, 3, 4].  Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Tags: Array
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * Think as cluster merge, a single number is a cluster with length = 1
     *
     * 1) The key factors about a cluster is: lowest, highest, and length.
     * 2) Map lowest and highest to length. To merge two neighbor clusters,
     *    only need to update it's new lowest and highest, with new length.
     * 3) For every a[i], checking its neighbor a[i]-1 and a[i]+1 is enough.
     */
    int longestConsecutive(vector<int>& numbers) {
        int max_length = 1;
        // map x to the length of longest range that contains x
        unordered_map<int, int> dict;
        for (int x : numbers) {
            if (dict.find(x) != dict.end())
                continue;
            dict[x] = 1;
            if (dict.find(x-1) != dict.end())
                max_length = max(max_length, merge(x-1, x, dict));
            if (dict.find(x+1) != dict.end())
                max_length = max(max_length, merge(x, x+1, dict));
        }
        return max_length;
    }

    int merge(int left, int right, unordered_map<int, int>& dict) {
        int lower = left - dict[left] + 1;
        int upper = right + dict[right] - 1;
        int length = upper - lower + 1;
        dict[lower] = dict[upper] = length;
        return length;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> num((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << Solution().longestConsecutive(num) << endl;
    }
    return 0;
}
