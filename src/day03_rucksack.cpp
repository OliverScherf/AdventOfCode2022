#include "helpers.hpp"
#include <cassert>
#include <map>
#include <string>
#include <vector>

struct Rucksack {
  std::string left{};
  std::string right{};
  Rucksack(const std::string &left_, const std::string &right_)
      : left(left_), right(right_) {}
};

template <>
Rucksack getAs(const std::string &s) {
  auto size = s.size();
  assert(size % 2 == 0);
  return Rucksack(s.substr(0, size / 2), s.substr(size / 2));
}

char findCommonChar(Rucksack rucksack) {
  std::map<char, uint64_t> character_occurences{};
  for (const auto &c : rucksack.left) {
    character_occurences[c]++;
  }

  for (const auto &c : rucksack.right) {
    if (character_occurences[c] != 0) {
      return c;
    }
  }
  std::cerr << "Could not find a common char in rucksack\n";
  std::abort();
}

uint8_t getCharScore(char c) {
  if (std::islower(c)) {
    // score for lower case characters starts with 1
    return static_cast<uint8_t>(c) - static_cast<uint8_t>('a') + +1;
  } else {
    // score for upper case characters starts with 27
    return static_cast<uint8_t>(c) - static_cast<uint8_t>('A') + 27;
  }
}

auto part1(const std::vector<Rucksack> &rucksack) {
  uint64_t sum{};
  for (const auto &r : rucksack) {
    auto c = findCommonChar(r);
    sum += getCharScore(c);
  }
  return sum;
}

struct Group {
  std::string elf1{};
  std::string elf2{};
  std::string elf3{};
  std::array<std::string, 3> lines;
  Group(std::string s1, std::string s2, std::string s3)
      : elf1(s1), elf2(s2), elf3(s3) {}
};

std::vector<Group> createGroups(const std::vector<std::string> &input) {
  assert(input.size() % 3 == 0);
  std::vector<Group> groups;
  for (std::size_t i = 0; i < input.size(); i += 3) {
    groups.emplace_back(input[i + 0], input[i + 1], input[i + 2]);
  }
  return groups;
}

char findCommonChar(Group group) {
  std::map<char, uint64_t> character_occurences1{};
  std::map<char, uint64_t> character_occurences2{};
  for (const auto &c : group.elf1) {
    character_occurences1[c]++;
  }
  for (const auto &c : group.elf2) {
    character_occurences2[c]++;
  }

  for (const auto &c : group.elf3) {
    if (character_occurences1[c] != 0 && character_occurences2[c] != 0) {
      return c;
    }
  }
  std::cerr << "Could not a common char in the group.\n";
  std::abort();
}

auto part2(const std::vector<std::string> &input) {
  uint64_t sum{};
  std::vector<Group> groups = createGroups(input);
  // create groups
  for (const auto &g : groups) {
    auto c = findCommonChar(g);
    sum += getCharScore(c);
  }
  return sum;
}

int main() {
  const auto input1 = readFileToVector<Rucksack>(INPUT_FILE_PATH);
  auto part1_score = part1(input1);
  std::cout << "Part 1 score " << part1_score << '\n';
  assert(part1_score == 7850);

  const auto input2 = readFileToVector<std::string>(INPUT_FILE_PATH);
  auto part2_score = part2(input2);
  std::cout << "Part 2 score " << part2_score << '\n';
  assert(part2_score == 2581);
  return 0;
}
