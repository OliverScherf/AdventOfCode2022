#include <cassert>
#include <helpers.hpp>
#include <iostream>
#include <map>
#include <numeric>
#include <ranges>
#include <utility>

// clang-format off
enum class opponent_code {
  ROCK = 'A',
  PAPER = 'B',
  SCISSORS = 'C'
};

enum class me_code {
  ROCK = 'X',
  PAPER = 'Y',
  SCISSORS = 'Z'
};

enum class desired_result_code {
  LOSS = 'X',
  DRAW = 'Y',
  WIN = 'Z'
};

enum class rps_result_points {
  WIN = 6,
  DRAW = 3,
  LOSS = 0
};

std::map<desired_result_code, rps_result_points> result_points_map {
  { desired_result_code::WIN,  rps_result_points::WIN },
  { desired_result_code::DRAW, rps_result_points::DRAW },
  { desired_result_code::LOSS, rps_result_points::LOSS }
};

std::map<me_code, std::uint64_t> me_shape_bonus_table{
    {me_code::ROCK,     1},
    {me_code::PAPER,    2},
    {me_code::SCISSORS, 3}
};

std::map<std::pair<opponent_code, me_code>, rps_result_points> rps_game_result_table = {
  { std::make_pair(opponent_code::ROCK,     me_code::ROCK),     rps_result_points::DRAW},
  { std::make_pair(opponent_code::PAPER,    me_code::PAPER),    rps_result_points::DRAW},
  { std::make_pair(opponent_code::SCISSORS, me_code::SCISSORS), rps_result_points::DRAW},
  { std::make_pair(opponent_code::SCISSORS, me_code::ROCK),     rps_result_points::WIN},
  { std::make_pair(opponent_code::ROCK,     me_code::PAPER),    rps_result_points::WIN},
  { std::make_pair(opponent_code::PAPER,    me_code::SCISSORS), rps_result_points::WIN},
  { std::make_pair(opponent_code::PAPER,    me_code::ROCK),     rps_result_points::LOSS},
  { std::make_pair(opponent_code::SCISSORS, me_code::PAPER),    rps_result_points::LOSS},
  { std::make_pair(opponent_code::ROCK,     me_code::SCISSORS), rps_result_points::LOSS}
};

std::map<std::pair<opponent_code, desired_result_code>, me_code> rps_game_desired_table = {
  { std::make_pair(opponent_code::SCISSORS, desired_result_code::WIN),  me_code::ROCK},
  { std::make_pair(opponent_code::ROCK,     desired_result_code::WIN),  me_code::PAPER},
  { std::make_pair(opponent_code::PAPER,    desired_result_code::WIN),  me_code::SCISSORS},
  { std::make_pair(opponent_code::ROCK,     desired_result_code::DRAW), me_code::ROCK},
  { std::make_pair(opponent_code::PAPER,    desired_result_code::DRAW), me_code::PAPER},
  { std::make_pair(opponent_code::SCISSORS, desired_result_code::DRAW), me_code::SCISSORS},
  { std::make_pair(opponent_code::PAPER,    desired_result_code::LOSS), me_code::ROCK},
  { std::make_pair(opponent_code::SCISSORS, desired_result_code::LOSS), me_code::PAPER},
  { std::make_pair(opponent_code::ROCK,     desired_result_code::LOSS), me_code::SCISSORS}
};
// clang-format on

template <>
std::pair<opponent_code, me_code> getAs(const std::string &s) {
  std::stringstream ss{s};

  char opponent_char{};
  char me_char{};
  ss >> opponent_char;
  ss >> me_char;
  return std::make_pair(static_cast<opponent_code>(opponent_char),
                        static_cast<me_code>(me_char));
}

template <>
std::pair<opponent_code, desired_result_code> getAs(const std::string &s) {
  std::stringstream ss{s};

  char opponent_char{};
  char desired_result_char{};
  ss >> opponent_char;
  ss >> desired_result_char;
  return std::make_pair(static_cast<opponent_code>(opponent_char),
                        static_cast<desired_result_code>(desired_result_char));
}

auto part1(const std::vector<std::pair<opponent_code, me_code>> &input) {
  auto sum{0UL};
  for (auto &rps_game : input) {
    auto game_bonus =
        static_cast<std::uint64_t>(rps_game_result_table.at(rps_game));
    auto shape_bonus =
        static_cast<std::uint64_t>(me_shape_bonus_table.at(rps_game.second));
    sum += game_bonus + shape_bonus;
  }
  return sum;
}

auto part2(
    const std::vector<std::pair<opponent_code, desired_result_code>> &input) {
  auto sum{0UL};
  for (auto &rps_game : input) {
    auto mee = rps_game_desired_table.at(rps_game);
    auto game_bonus =
        static_cast<std::uint64_t>(result_points_map.at(rps_game.second));
    auto shape_bonus = static_cast<std::uint64_t>(me_shape_bonus_table.at(mee));
    sum += game_bonus + shape_bonus;
  }
  return sum;
}

int main() {
  const auto input1 =
      readFileToVector<std::pair<opponent_code, me_code>>(INPUT_FILE_PATH);
  auto part1_score = part1(input1);
  std::cout << "Part 1 score " << part1_score << '\n';
  assert(part1_score == 15691);

  const auto input2 =
      readFileToVector<std::pair<opponent_code, desired_result_code>>(
          INPUT_FILE_PATH);
  auto part2_score = part2(input2);
  std::cout << "Part 2 score " << part2_score << '\n';
  assert(part2_score == 12989);
  return 0;
}
