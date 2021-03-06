
#include "passvalue.h"
#include <iostream>
#include <optional>

std::optional<long> run(std::string command) {
    if (!std::system(command.c_str())) {
        auto c = readValue<long>("timing.txt");
        std::cout << "got " << c << std::endl;
        return c;
    }
    std::cerr << "failed\n";
    return std::nullopt;
}

int main(int argc, char *argv[]) {
    std::cout << "benchmark:" << std::endl;

    auto a = run("./naive 200000");
    auto b = run("./basic 200000");
    auto c = run("./magic 200000");

    std::cout << *a << " vs " << *b << " vs " << *c << std::endl;

    return 0;
}
