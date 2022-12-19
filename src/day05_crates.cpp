#include "helpers.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <stack>
#include <string>
#include <vector>

struct Move {
  uint64_t count{};
  uint64_t stack_from{};
  uint64_t stack_to{};
};

template <>
Move getAs(const std::string &s) {
  Move move;
  std::stringstream ss{s};
  std::string _;
  ss >> _;
  ss >> move.count;
  ss >> _;
  ss >> move.stack_from;
  ss >> _;
  ss >> move.stack_to;
  return move;
}

std::vector<std::stack<char>>
create_stacks(const std::vector<std::string> &input) {
  std::vector<std::stack<char>> stacks(input.front().size());
  for (auto it = input.rbegin(); it != input.rend(); ++it) {
    auto line = *it;
    for (std::size_t i = 0; i < line.size(); ++i) {
      char c = line[i];
      if (c != ' ') {
        stacks[i].push(c);
      }
    }
  }
  return stacks;
}

template <typename Mover>
std::string move_crates(const std::vector<Move> &input_moves,
                        std::vector<std::stack<char>> stacks, Mover do_move) {
  for (const auto move : input_moves) {
    do_move(stacks, move);
  }
  std::string result{};
  for (auto &s : stacks) {
    result.append(std::string{s.top()});
  }
  return result;
}

void part1_mover(std::vector<std::stack<char>> &stacks, Move move) {
  for (std::size_t i = 0; i < move.count; ++i) {
    auto to_move = stacks[move.stack_from - 1].top();
    stacks[move.stack_from - 1].pop(); // wow pop() does return void ?!
    stacks[move.stack_to - 1].push(to_move);
  }
}

void part2_mover(std::vector<std::stack<char>> &stacks, Move move) {
  std::vector<char> crate_chunk{};
  for (std::size_t i = 0; i < move.count; ++i) {
    auto to_move = stacks[move.stack_from - 1].top();
    stacks[move.stack_from - 1].pop(); // wow pop() does return void ?!
    crate_chunk.push_back(to_move);
  }
  for (auto it = crate_chunk.rbegin(); it != crate_chunk.rend(); ++it) {
    stacks[move.stack_to - 1].push(*it);
  }
}

int main() {
  const auto input_moves = readFileToVector<Move>(INPUT_FILE_PATH_MOVES);
  const auto input_crates =
      readFileToVector<std::string>(INPUT_FILE_PATH_CRATES);
  auto stacks = create_stacks(input_crates);
  auto part1_solution = move_crates(input_moves, stacks, part1_mover);
  std::cout << "Part 1 solution " << part1_solution << '\n';
  assert(part1_solution == "SBPQRSCDF");
  auto part2_solution = move_crates(input_moves, stacks, part2_mover);
  std::cout << "Part 2 solution " << part2_solution << '\n';
  assert(part2_solution == "RGLVRCQSB");
  return 0;
}
