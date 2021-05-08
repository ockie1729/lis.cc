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
