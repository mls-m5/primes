#include "primesettings.h"
#include "timing.h"
#include "utils.h"
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
    auto settings = PrimeSettings{argc, argv};

    auto timing = Timing{"basic"};

    int numPrimes = 0;

    for (Integer i = 2; i < settings.num; ++i) {
        bool isPrime = true;
        for (Integer j = 2; j <= std::sqrt(i);
             ++j) { // the sqrt is the optimization
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
