#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include <gtest/gtest.h>
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include "common/util.h"

ABSL_FLAG(std::string, path, "", "Path to data.txt");

int main(int argc, char **argv) {
  /*
   * We can safely call `testing::InitGoogleTest()` before `absl::ParseCommandLine()` as
   * long as we don't use custom command-line flags in our test code since GoogleTest
   * ignores command-line flags it doesn't understand.
   */
  testing::InitGoogleTest(&argc, argv);

  absl::ParseCommandLine(argc, argv);

  std::cout << "================================" << std::endl;
  std::cout << "__FILE__    = " << __FILE__ << std::endl;
  std::cout << "__cplusplus = " << __cplusplus << std::endl;
  std::cout << "working dir = " << std::filesystem::current_path() << std::endl;
  std::cout << "FLAGS_path  = " << absl::GetFlag(FLAGS_path) << std::endl;
  for (int i = 0; i < argc; ++i) {
    std::cout << "argv[" << i << "]     = " << argv[i] << std::endl;
  }

  // Print contents of data.txt
  std::string line;
  std::ifstream ifs(absl::GetFlag(FLAGS_path));
  while (std::getline(ifs, line)) {
    std::cout << line << std::endl;
  }

  return RUN_ALL_TESTS();
}
