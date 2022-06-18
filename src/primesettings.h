#pragma once

#include <string>
#include <vector>

using Integer = long;

struct PrimeSettings {
    Integer num = 100;

    PrimeSettings(int argc, char *argv[]) {
        auto args = std::vector<std::string>{argv + 1, argv + argc};

        for (size_t i = 0; i < args.size(); ++i) {
            auto arg = args.at(i);

            num = std::stol(arg);
        }
    }
};
