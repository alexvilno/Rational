#include <iostream>
#include <string>
#include "Rational.h"

int main() {
    Rational a, b;
    std::string cmd;

    std::cin >> a >> b >> cmd;

    if (cmd == "+") {
        std::cout << a + b;
    } else if (cmd == "-") {
        std::cout << a - b;
    } else if (cmd == "*") {
        std::cout << a * b;
    } else if (cmd == "/") {
        std::cout << a / b;
    } else if (cmd == "==") {
        std::cout << (a == b);
    } else if (cmd == "!=") {
        std::cout << (a != b);
    } else if (cmd == ">") {
        std::cout << (a > b);
    } else if (cmd == "<") {
        std::cout << (a < b);
    } else if (cmd == ">=") {
        std::cout << (a >= b);
    } else if (cmd == "<=") {
        std::cout << (a <= b);
    }

    return 0;
}
