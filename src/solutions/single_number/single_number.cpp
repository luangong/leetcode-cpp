/**
 * Single Number
 *
 * Given an array of integers, every element appears twice except for one.  Find that
 * single one.
 *
 * Note: Your algorithm should have a linear runtime complexity.  Could you implement it
 * without using extra memory?
 *
 * Tags: Hash Table, Bit Manipulation
 */

#include <numeric>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"

class Solution {
 public:
  int singleNumber(const std::vector<int>& nums) const {
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        result ^= nums[i];
    }
    return result;
  }

  int singleNumber2(const std::vector<int>& nums) const {
    int result = 0;
    std::for_each(nums.cbegin(), nums.cend(), [&result](int elem){ result ^= elem; });
    return result;
  }

  int singleNumber3(const std::vector<int>& nums) const {
    return std::accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<int>());
  }
};

namespace {

// The fixture for testing class Solution.
class SolutionTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body is empty.

  SolutionTest() {
    // You can do set-up work for each test here.
  }

  ~SolutionTest() override {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up and cleaning up each
  // test, you can define the following methods:

  void SetUp() override {
    // Code here will be called immediately after the constructor (right before each test).
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Solution.
};

// Tests that the Solution::singleNumber() method does Abc.
// TEST_F(SolutionTest, singleNumber) {
//   const std::string input_filepath = "this/package/testdata/myinputfile.dat";
//   const std::string output_filepath = "this/package/testdata/myoutputfile.dat";
//   Solution solution
//   EXPECT_EQ(solution.singleNumber(input_filepath, output_filepath), 0);
// }

// Tests that Solution::singleNumber() returns the only number in the list.
TEST_F(SolutionTest, SingleNumberReturnsTheOnlyNumber) {
  EXPECT_EQ(Solution().singleNumber({ 1 }), 1);
}

// Tests that Solution::singleNumber() returns the single number.
TEST_F(SolutionTest, SingleNumberReturns3) {
  EXPECT_EQ(Solution().singleNumber({ 1, 1, 2, 2, 3 }), 3);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
