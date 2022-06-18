#include "primesettings.h"
#include <iostream>

// The worst possible implementation
int main(int argc, char *argv[]) {
    auto settings = PrimeSettings{argc, argv};

    for (Integer i = 2; i < settings.num; ++i) {
        bool isPrime = true;
        for (Integer j = 2; j < i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            std::cout << i << "\n";
        }
    }

    std::cout << "done" << std::endl;

    return 0;
}
