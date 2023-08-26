#include <iostream>
#include <string>

#include <gtest/gtest.h>
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

ABSL_FLAG(std::string, test_cases, "", "Relative path to test_cases.yaml");

int main(int argc, char **argv) {
  /*
   * http://google.github.io/googletest/reference/testing.html#InitGoogleTest
   *
   * `testing::InitGoogleTest()` parses the command line for the flags that GoogleTest
   * recognizes.  Whenever a GoogleTest flag is seen, it is removed from `argv`, and
   * `*argc` is decremented.
   *
   * We must call `absl::ParseCommandLine()` before calling `absl::InitGoogleTest()` since
   * during the test preparation phase we will load a YAML file to which the path is
   * specified by a custom command-line flag, and thus this command-line flag must be
   * parsed by `absl::ParseCommandLine()` first.
   *
   * Note that `absl::ParseCommandLine()` doesn’t change `argc` or `*argv` after parsing
   * the command-line, but it complains when it comes across an unknown flag unless
   * `--undefok=<unknown-flag>` is also specified.  See `.bazelrc` in the workspace root
   * for more information.
   */
  absl::ParseCommandLine(argc, argv);
  testing::InitGoogleTest(&argc, argv);
  // std::cerr << "current directory = " << std::filesystem::current_path() << std::endl;
  // std::cout << "--test_cases = " << absl::GetFlag(FLAGS_test_cases) << std::endl;
  // for (auto i = 0; i < argc; ++i) {
  //   std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  // }
  return RUN_ALL_TESTS();
}
