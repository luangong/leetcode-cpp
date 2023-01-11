/*
 * Jump Game II
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example: Given array A = [2,3,1,1,4]. The minimum number of jumps to
 * reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to
 * the last index.)
 *
 * Tags: Array, Greedy
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
 public:
  /*
   * We use "last" to keep track of the maximum distance that has been reached
   * by using the minimum jumps `num_jumps`, whereas `curr` is the maximum distance
   * that can be reached by using `num_jumps + 1` steps. Thus,
   * curr = max(curr, i + A[i]) where 0 <= i <= last.
   */
  int jump(int A[], int n) {
    int num_jumps = 0;
    int prev_max_reach = 0;
    int curr_max_reach = 0;
    for (int i = 0; i < n; ++i) {
      if (i > prev_max_reach) {
        prev_max_reach = curr_max_reach;
        ++num_jumps;
      }
      curr_max_reach = max(curr_max_reach, i + A[i]);
    }
    return num_jumps;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    istringstream iss(line);
    vector<int> vec((istream_iterator<int>(iss)), istream_iterator<int>());
    cout << Solution().jump(&vec[0], vec.size()) << endl;
  }
  return 0;
}
