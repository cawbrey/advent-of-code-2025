#include <iostream>
#include <string>

int main() {
    uint dial = 50;
    uint numZeros = 0;

    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        uint number = std::stoi(line.substr(1)) % 100;

        if (line.at(0) == 'R')
            number = 100 - number;

        dial = (dial + number) % 100;

        if (dial == 0)
            numZeros++;
    }

    std::cout << std::to_string(numZeros) << std::endl;
}
