#include <string>
// #include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "absl/flags/declare.h"
// #include "absl/flags/flag.h"

ABSL_DECLARE_FLAG(std::string, testcases);

// #define MY_INSTANTIATE_TEST_CASE_P(test_suite_name) \
//   INSTANTIATE_TEST_SUITE_P(                         \
//       SolutionParameterizedTest,                    \
//       test_suite_name,                              \
//       testing::ValuesIn(loadTestCasesFromJsonFile(absl::GetFlag(FLAGS_testcases))))

nlohmann::json loadTestCasesFromJsonFile(const std::string& filename);
