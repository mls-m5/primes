#include "primesettings.h"
#include "timing.h"
#include "utils.h"
#include <iostream>

// The worst possible implementation
int main(int argc, char *argv[]) {
    auto settings = PrimeSettings{argc, argv};

    auto timing = Timing{"naive"};

    int numPrimes = 0;

    for (Integer i = 2; i < settings.num; ++i) {
        bool isPrime = true;
        for (Integer j = 2; j < i; ++j) {
            if (isDividableBy(i, j)) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            //            std::cout << i << "\n";
            ++numPrimes;
        }
    }

    std::cout << "number of primes: " << numPrimes << std::endl;
}
