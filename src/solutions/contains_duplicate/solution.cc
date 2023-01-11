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
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include <yaml-cpp/yaml.h>

#include "common/util.h"

class Solution {
 public:
  // Solution 1: Check if the total number of elements is greater than the number of
  // unique elements
  bool containsDuplicate(const std::vector<int>& nums) {
    return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
  }

  // Solution 2: Iterate through the elements and check if an element is seen/visited
  // before
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

//////////////////////////////////////////////////////////////////////////////////////////

typedef YAML::Node TestCase;

class SolutionTestFixture : public testing::TestWithParam<TestCase> {
 public:
  void SetUp() override {}
  void TearDown() override {}
  Solution solution;
};

TEST_P(SolutionTestFixture, TestContainsDuplicate) {
  const auto& testCase = testing::TestWithParam<TestCase>::GetParam();
  EXPECT_EQ(
      testCase["expected"].as<bool>(),
      solution.containsDuplicate(testCase["nums"].as<std::vector<int>>()));
}

TEST_P(SolutionTestFixture, TestContainsDuplicate2) {
  const auto& testCase = testing::TestWithParam<TestCase>::GetParam();
  EXPECT_EQ(
      testCase["expected"].as<bool>(),
      solution.containsDuplicate2(testCase["nums"].as<std::vector<int>>()));
}

INSTANTIATE_TEST_SUITE_P(
    SolutionParameterizedTest,
    SolutionTestFixture,
    testing::ValuesIn(loadTestCasesFromYamlFile(absl::GetFlag(FLAGS_test_cases))));
