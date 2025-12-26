#include <iostream>
#include <string>

int main() {
    constexpr uint8_t DIAL_SIZE = 100;

    uint8_t position = 50;
    uint numZeros = 0;

    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        int rotation = std::stoi(line.substr(1));
        bool isRight = line.at(0) == 'R';

        numZeros += rotation / DIAL_SIZE;

        if (isRight) {
            numZeros += (rotation % DIAL_SIZE) >= (DIAL_SIZE - position);

            position = (position + rotation) % DIAL_SIZE;
        } else {
            numZeros += position != 0 && rotation % DIAL_SIZE >= position;

            position = (position - rotation % DIAL_SIZE + DIAL_SIZE) % DIAL_SIZE;
        }
    }

    std::cout << std::to_string(numZeros) << std::endl;
}