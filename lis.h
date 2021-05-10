#ifndef LIS_H_
#define LIS_H_

#include<vector>
#include<string>

void repl();

std::vector<std::string> split_str(std::string);
std::vector<std::string> tokenize(std::string);
int eval(std::vector<std::string>);

#endif  // LIS_H_
