#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <filesystem>
#include <tuple>
#include <vector>
#include <unordered_set>

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include "common/util.h"

using json = nlohmann::json;

class Solution {
 public:
  // Solution 1: Check if the total number of elements is greater than the number of unique elements
  bool containsDuplicate(const std::vector<int>& nums) {
    return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
  }

  // Solution 2: Iterate through the elements and check if an element is seen/visited before
  bool containsDuplicate2(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (auto num : nums) {
      if (seen.find(num) != seen.end()) {
        return true;
      }
      seen.insert(num);
    }
    return false;
  }
};

//----------------------------------------------------------------------------------------

typedef json TestCase;

class SolutionTestFixture : public testing::TestWithParam<TestCase> {
 public:
  void SetUp() override {}
  void TearDown() override {}
  Solution solution;
};

TEST_P(SolutionTestFixture, TestContainsDuplicate) {
  const json& testCase = testing::TestWithParam<json>::GetParam();
  EXPECT_EQ(testCase.at("expected"), solution.containsDuplicate(testCase.at("nums")));
}

TEST_P(SolutionTestFixture, TestContainsDuplicate2) {
  const json& testCase = testing::TestWithParam<json>::GetParam();
  EXPECT_EQ(testCase.at("expected"), solution.containsDuplicate2(testCase.at("nums")));
}

INSTANTIATE_TEST_SUITE_P(
    SolutionParameterizedTest,
    SolutionTestFixture,
    testing::ValuesIn(loadTestCasesFromJsonFile(absl::GetFlag(FLAGS_testcases))));
