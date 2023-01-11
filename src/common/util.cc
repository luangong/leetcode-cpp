#include <fstream>
#include "util.h"

nlohmann::json loadTestCasesFromJsonFile(const std::string& filename) {
  return nlohmann::json::parse(std::ifstream(filename));
}
