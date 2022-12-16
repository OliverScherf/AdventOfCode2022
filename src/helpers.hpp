#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
T getAs(const std::string &s) {
  std::stringstream ss{s};
  T t;
  ss >> t;
  return t;
}

// template <typename T>
template <>
std::pair<char, char> getAs(const std::string &s) {
  std::stringstream ss{s};
  std::pair<char, char> pair;
  ss >> pair.first;
  ss >> pair.second;
  return pair;
}

namespace {
auto readLinesFromFile(const std::string &file) -> std::vector<std::string> {
  std::vector<std::string> inputs;
  std::ifstream infile(file);
  std::string line;
  while (std::getline(infile, line)) {
    inputs.push_back(line);
  }
  return inputs;
}

} // namespace

template <typename T>
auto readFileToVector(const std::string &file) -> const std::vector<T> {

  auto lines = readLinesFromFile(file);

  std::vector<T> inputs;
  inputs.reserve(lines.size());
  for (auto &&line : lines) {
    T converted = getAs<T>(line);
    inputs.emplace_back(converted);
  }
  return inputs;
}
