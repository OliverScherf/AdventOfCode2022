#include "helpers.hpp"
#include <cassert>
#include <string>
#include <vector>

struct Range {
  uint64_t left{};
  uint64_t right{};
};

struct Pair {
  Range elf1{};
  Range elf2{};
};

template <>
Pair getAs(const std::string &s) {
  Pair pair{};

  std::stringstream ss{s};
  ss >> pair.elf1.left;
  ss >> pair.elf1.right;
  ss >> pair.elf2.left;
  ss >> pair.elf2.right;
  return pair;
}

auto part1(const std::vector<Pair> &pairs) {
  auto does_fully_overlap = [](Pair pair) {
    if (pair.elf1.left >= pair.elf2.left) {
      if (pair.elf1.right <= pair.elf2.right) {
        return true;
      }
    }
    if (pair.elf2.left >= pair.elf1.left) {
      if (pair.elf2.right <= pair.elf1.right) {
        return true;
      }
    }
    return false;
  };

  uint64_t sum{};
  for (const auto &p : pairs) {
    sum += does_fully_overlap(p);
  }
  return sum;
}

auto part2(const std::vector<Pair> &pairs) {
  auto does_overlap = [](Pair pair) {
    return pair.elf1.left <= pair.elf2.right &&
           pair.elf2.left <= pair.elf1.right;
  };

  uint64_t sum{};
  for (const auto &p : pairs) {
    sum += does_overlap(p);
  }
  return sum;
}

int main() {
  const auto input = readFileToVector<Pair>(INPUT_FILE_PATH);
  auto part1_score = part1(input);
  std::cout << "Part 1 score " << part1_score << '\n';
  assert(part1_score == 500);
  const auto input1 = readFileToVector<Pair>(INPUT_FILE_PATH);
  auto part2_score = part2(input);
  std::cout << "Part 2 score " << part2_score << '\n';
  assert(part2_score == 815);
  return 0;
}
