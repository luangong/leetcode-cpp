#include <fstream>
#include <vector>
#include "util.h"

std::vector<YAML::Node> loadTestCasesFromYamlFile(const std::string &filename) {
  return YAML::LoadFile(filename).as<std::vector<YAML::Node>>();
}
