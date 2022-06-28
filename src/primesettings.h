#pragma once

#include <iostream>
#include <string>
#include <vector>

using Integer = long;

struct PrimeSettings {
    static constexpr std::string_view helpStr = {R"_(
usage:
--print               print
--help                print this text
)_"};

    Integer num = 100;
    bool shouldPrintNumebers = false;

    PrimeSettings(int argc, char *argv[]) {
        auto args = std::vector<std::string>{argv + 1, argv + argc};

        for (size_t i = 0; i < args.size(); ++i) {
            auto arg = args.at(i);

            if (arg == "--print") {
                shouldPrintNumebers = true;
            }
            else if (arg == "--help") {
                std::cout << helpStr << std::endl;
                std::exit(0);
            }
            else {
                num = std::stol(arg);
            }
        }
    }
};
