#include <cassert>
#include <helpers.hpp>
#include <iostream>
#include <numeric>
#include <ranges>

std::vector<int64_t>
create_calories_per_elv_list(const std::vector<std::string> &inputs) {
  std::vector<int64_t> elves;
  int64_t sum{};
  for (auto &&line : inputs) {
    if ("" == line) {
      elves.push_back(sum);
      sum = 0;
      continue;
    }
    sum += getAs<int64_t>(line);
  }
  return elves;
}

int64_t part1(const std::vector<std::string> &inputs) {
  std::vector<int64_t> elves = create_calories_per_elv_list(inputs);
  return *std::max_element(elves.begin(), elves.end());
}

int64_t part2(const std::vector<std::string> &inputs) {
  std::vector<int64_t> elves = create_calories_per_elv_list(inputs);
  std::sort(elves.begin(), elves.end());

  constexpr int64_t N_LARGEST = 3;
  std::vector<int64_t> elves_most_calories(N_LARGEST);
  // Sort & copy until we found the N_LARGEST elves
  std::partial_sort_copy(elves.begin(), elves.end(), elves_most_calories.begin(), elves_most_calories.end(),
                         std::greater<>());
  return std::accumulate(elves_most_calories.begin(), elves_most_calories.end(), 0, std::plus<>());
}

int main() {
  const auto input = readFileToVector<std::string>(INPUT_FILE_PATH);
  auto solution_part1 = part1(input);
  std::cout << "solution part1: " << solution_part1 << std::endl;
  assert(solution_part1 == 67016);

  auto solution_part2 = part2(input);
  std::cout << "solution part2: " << solution_part2 << std::endl;
  assert(solution_part2 == 200116);
  return 0;
}
