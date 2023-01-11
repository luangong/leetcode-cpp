#include <string>
#include <vector>
#include "absl/flags/declare.h"
#include <yaml-cpp/yaml.h>

ABSL_DECLARE_FLAG(std::string, test_cases);

// #define MY_INSTANTIATE_TEST_CASE_P(test_suite_name) \
//   INSTANTIATE_TEST_SUITE_P(                         \
//       SolutionParameterizedTest,                    \
//       test_suite_name,                              \
//       testing::ValuesIn(loadTestCasesFromYamlFile(absl::GetFlag(FLAGS_test_cases))))

std::vector<YAML::Node> loadTestCasesFromYamlFile(const std::string& filename);
