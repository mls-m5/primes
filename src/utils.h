#pragma once

#include <iostream>

template <typename T>
bool isDividableBy(T a, T b) {
    return a % b == 0;
}

void printPrime(long index, long number) {
    std::cout << index << ": " << number;
}
