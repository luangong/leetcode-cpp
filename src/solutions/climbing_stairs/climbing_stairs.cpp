/**
 * Climbing Stairs
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Tags: Dynamic Programming
 */

#include <iostream>

class Solution {
 public:
  int climbStairs(int n) {
    int x = 0, y = 1, z = 0;
    for (int i = 0; i < n; ++i) {
      z = x + y;
      x = y;
      y = z;
    }
    return z;
  }
};

int main(int argc, char **argv) {
  int n;
  while (std::cin >> n) {
    std::cout << Solution().climbStairs(n) << std::endl;
  }
  return 0;
}
