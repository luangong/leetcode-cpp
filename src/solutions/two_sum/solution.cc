/**
 * Two Sum
 *
 * Given an array of integers `nums` and an integer `target`, return indices of the two
 * numbers such that they add up to `target`.
 *
 * You may assume that each input would have exactly one solution, and you may not use the
 * same element twice.
 *
 * You can return the answer in any order.
 *
 * Example 1:
 *
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 *
 * Input: nums = [3, 2, 4], target = 6
 * Output: [1, 2]
 *
 * Example 3:
 *
 * Input: nums = [3, 3], target = 6
 * Output: [0, 1]
 *
 * Constraints:
 *
 * * 2 <= nums.length <= 10^4
 * * -10^9 <= nums[i] <= 10^9
 * * -10^9 <= target <= 10^9
 *
 * Only one valid answer exists.
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
 *
 * Tags: Array, Hash Table
 */
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include <yaml-cpp/yaml.h>

#include "common/util.h"

class Solution {
 public:
  /**
   * 方法一：先排序然后从两头往中间查找，需要 O(nlgn) 时间和 O(n) 空间
   */
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::vector<std::pair<int, int>> vec(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      vec[i] = std::make_pair(nums[i], i);
    }
    std::sort(vec.begin(), vec.end());
    std::vector<int> result(2);
    std::vector<int>::size_type i = 0, j = vec.size() - 1;
    while (i < j) {
      if (vec[i].first + vec[j].first < target) {
        ++i;
      } else if (vec[i].first + vec[j].first > target) {
        --j;
      } else {
        result[0] = std::min(vec[i].second, vec[j].second);
        result[1] = std::max(vec[i].second, vec[j].second);
        break;
      }
    }
    return result;
  }
};

class Solution2 {
 public:
  /**
   * 方法二：用 hash 表，需要 O(n) 时间和 O(n) 空间
   */
  std::vector<int> twoSum2(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      auto rest = target - nums[i];
      if (map.find(rest) != map.end()) {
        return std::vector<int>{ map[rest], i };
      } else {
        map[nums[i]] = i;
      }
    }
    return std::vector<int>();
  }
};

//----------------------------------------------------------------------------------------

/*
 * Test Fixtures: Using the Same Data Configuration for Multiple Tests
 * http://google.github.io/googletest/primer.html#same-data-multiple-tests
 *
 * If you find yourself writing two or more tests that operate on similar data, you can
 * use a test fixture.  This allows you to reuse the same configuration of objects for
 * several different tests.
 *
 * For each test defined with `TEST_F()`, googletest will create a fresh test fixture at
 * runtime, immediately initialize it via `SetUp()`, run the test, clean up by calling
 * `TearDown()`, and then delete the test fixture.  Note that different tests in the same
 * test suite have different test fixture objects, and googletest always deletes a test
 * fixture before it creates the next one.  googletest does not reuse the same test
 * fixture for multiple tests.  Any changes one test makes to the fixture do not affect
 * other tests.
 */

/*
 * How to Write Value-Parameterized Tests
 * http://google.github.io/googletest/advanced.html#value-parameterized-tests
 *
 * To write value-parameterized tests, first you should define a fixture class.  It must
 * be derived from both `testing::Test` and `testing::WithParamInterface<T>` (the latter
 * is a pure interface), where `T` is the type of your parameter values.  For convenience,
 * you can just derive the fixture class from `testing::TestWithParam<T>`, which itself is
 * derived from both `testing::Test` and `testing::WithParamInterface<T>`.  `T` can be any
 * copyable type.  If it’s a raw pointer, you are responsible for managing the lifespan of
 * the pointed values.
 */

typedef YAML::Node TestCase;

class SolutionTestFixture : public testing::TestWithParam<TestCase> {
 public:
  // TODO: Implement all the usual fixture class members here.
  // To access the test parameter, call `testing::TestWithParam<T>::GetParam()`.
  void SetUp() override {}
  void TearDown() override {}
  Solution solution;
};

/*
 * Then, use the `TEST_P()` macro to define as many test patterns using this fixture as
 * you want.  The `_P` suffix is for "parameterized" or "pattern", whichever you prefer to
 * think.
 */
TEST_P(SolutionTestFixture, TestTwoSum) {
  auto testCase = testing::TestWithParam<TestCase>::GetParam();
  const std::vector<int>& expected = testCase["expected"].as<std::vector<int>>();
  const std::vector<int>& nums = testCase["nums"].as<std::vector<int>>();
  int target = testCase["target"].as<int>();
  EXPECT_EQ(expected, solution.twoSum(nums, target));
}

class SolutionTestFixture2 : public testing::TestWithParam<TestCase> {
 public:
  // TODO: Implement all the usual fixture class members here.
  // To access the test parameter, call `testing::TestWithParam<T>::GetParam()`.
  void SetUp() override {}
  void TearDown() override {}
  Solution2 solution;
};

TEST_P(SolutionTestFixture2, TestTwoSum) {
  auto testCase = testing::TestWithParam<TestCase>::GetParam();
  const std::vector<int>& expected = testCase["expected"].as<std::vector<int>>();
  const std::vector<int>& nums = testCase["nums"].as<std::vector<int>>();
  int target = testCase["target"].as<int>();
  EXPECT_EQ(expected, solution.twoSum2(nums, target));
}

/*
 * Finally, you can use the `INSTANTIATE_TEST_SUITE_P()` macro to instantiate the test
 * suite with any set of parameters you want.  GoogleTest defines a number of functions
 * for generating test parameters - see details at `INSTANTIATE_TEST_SUITE_P()` in the
 * Testing Reference.
 *
 * The first argument to `INSTANTIATE_TEST_SUITE_P()` is a unique name for the
 * instantiation of the test suite.  The next argument is the name of the test pattern,
 * and the last is the [parameter generator]
 * (http://google.github.io/googletest/reference/testing.html#param-generators).
 *
 * The parameter generator expression is not evaluated until GoogleTest is initialized
 * (via `InitGoogleTest()`).  Any prior initialization done in the `main()` function will
 * be accessible from the parameter generator, for example, the results of flag parsing.
 *
 * Note: Data files are in the directory relative to workspace root, rather than in the
 * same directory as the test binary.
 *
 * TODO: Make the path to test_cases.yml generic instead of containing the problem slug.
 * https://stackoverflow.com/a/19166388/4890253
 */
INSTANTIATE_TEST_SUITE_P(
    SolutionParameterizedTest,
    SolutionTestFixture,
    testing::ValuesIn(loadTestCasesFromYamlFile(absl::GetFlag(FLAGS_test_cases))));

INSTANTIATE_TEST_SUITE_P(
    Solution2ParameterizedTest,
    SolutionTestFixture2,
    testing::ValuesIn(loadTestCasesFromYamlFile(absl::GetFlag(FLAGS_test_cases))));
