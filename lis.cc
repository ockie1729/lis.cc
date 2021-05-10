#include <iostream>
#include <string>
#include <vector>

#include "./lis.h"

void repl() {
  while (true) {
    std::cout << "lis.cpp> ";

    std::string input_line;
    std::getline(std::cin, input_line);

    std::vector<std::string> split_tokens = split_str(input_line);

    // FIXME debug
    std::cout << "[debug] split line:" << std::endl;
    for (int i = 0; i < split_tokens.size(); i++) {
      std::cout << "- " << split_tokens[i] << std::endl;
    }
  }
}


bool is_whitespace(const char c) {
  return (c == ' ') || (c == '\n') || (c == '\t');
}


std::vector<std::string> split_str(const std::string original_str) {
  std::vector<std::string> split_tokens;
  std::string::size_type idx_token_start = -1;  // FIXME
  bool is_idx_in_token = false;

  for (std::string::size_type idx = 0; idx < original_str.size(); idx++) {
    // 行末以外でトークンの終わりを見つけた時
    if (is_idx_in_token && is_whitespace(original_str[idx])) {
      is_idx_in_token = false;

      std::string token =
        original_str.substr(idx_token_start, idx-idx_token_start);
      split_tokens.push_back(token);
    }

    // 行末でトークンの終わりを見つけた時
    if (is_idx_in_token && !(is_whitespace(original_str[idx])) &&
          (idx == original_str.size()-1)) {
      is_idx_in_token = false;

      const std::string token =
        original_str.substr(idx_token_start, (idx-idx_token_start)+1);
      split_tokens.push_back(token);
    }

    // トークンの始まりを見つけた時
    if (!(is_idx_in_token) && !(is_whitespace(original_str[idx]))) {
      is_idx_in_token = true;
      idx_token_start = idx;
    }
  }

  return split_tokens;
}


std::string replace_str(std::string original_str,
                           const std::string old_pattern,
                           const std::string new_pattern) {
  std::string::size_type pos(original_str.find(old_pattern));

  while (pos != std::string::npos) {
    original_str.replace(pos, old_pattern.length(), new_pattern);
    pos = original_str.find(old_pattern, pos + new_pattern.length());
  }

  return original_str;
}

std::vector<std::string> tokenize(const std::string target_str) {
  const auto s = replace_str(target_str, std::string("("), std::string(" ( "));
  const auto replaced = replace_str(s, std::string(")"), std::string(" ) "));

  const auto tokenized = split_str(replaced);

  return tokenized;
}

int eval(std::vector<std::string> input_tokens) {
  auto op = input_tokens[1];
  auto a = input_tokens[2];
  auto b = input_tokens[3];

  if (op == "+") {
    return std::stoi(a) + std::stoi(b);
  } else if (op == "-") {
    return std::stoi(a) - std::stoi(b);
  } else if (op == "*") {
    return std::stoi(a) * std::stoi(b);
  } else if (op == "/") {
    return std::stoi(a) / std::stoi(b);
  }

  return 3;
}
