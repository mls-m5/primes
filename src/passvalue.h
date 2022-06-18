#pragma once

#include <fstream>

template <typename T>
void writeValue(const T &value, std::string name = "passfile.txt") {
    std::ofstream{name} << value;
}

template <typename T>
T readValue(std::string name = "passfile.txt") {
    T value;
    std::ifstream{name} >> value;
    return value;
}
