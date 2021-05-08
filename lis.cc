#include <iostream>
#include <string>
#include "./lis.h"

void repl() {
  std::cout << "hello world!!" << std::endl;

  while (true) {
    std::cout << "lis.cpp> ";

    std::string s;
    std::cin >> s;

    std::cout << s << std::endl;
  }
}


bool is_whitespace(const char c) {
  return (c == ' ') || (c == '\n') || (c == '\t');
}


std::vector<std::string> split_str(const std::string input_str) {
  std::vector<std::string> split_tokens;
  std::string::size_type idx_token_start = -1;  // FIXME
  bool is_idx_in_token = false;

  for (std::string::size_type idx = 0; idx < input_str.size(); idx++) {
    // 行末以外でトークンの終わりを見つけた時
    if (is_idx_in_token && is_whitespace(input_str[idx])) {
      is_idx_in_token = false;

      std::string token =
        input_str.substr(idx_token_start, idx-idx_token_start);
      split_tokens.push_back(token);
    }

    // 行末でトークンの終わりを見つけた時
    if (is_idx_in_token && !(is_whitespace(input_str[idx])) &&
          (idx == input_str.size()-1)) {
      is_idx_in_token = false;

      const std::string token =
        input_str.substr(idx_token_start, (idx-idx_token_start)+1);
      split_tokens.push_back(token);
    }

    // トークンの始まりを見つけた時
    if (!(is_idx_in_token) && !(is_whitespace(input_str[idx]))) {
      is_idx_in_token = true;
      idx_token_start = idx;
    }
  }

  return split_tokens;
}
