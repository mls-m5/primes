#pragma once

#include "passvalue.h"
#include <chrono>
#include <iostream>
#include <string>

struct Timing {
    std::string name;
    std::chrono::high_resolution_clock::time_point start;
    long value = 0;

    Timing(std::string name)
        : name{name} {
        start = std::chrono::high_resolution_clock::now();
    };

    long count() {
        if (!value) {
            auto stop = std::chrono::high_resolution_clock::now();
            auto d = stop - start;
            value = std::chrono::duration_cast<std::chrono::microseconds>(d)
                        .count();
            writeValue(value, "timing.txt");
            return value;
        }
        return value;
    }

    ~Timing() {
        std::cout << name << ": " << count() << "µs" << std::endl;
    }
};
