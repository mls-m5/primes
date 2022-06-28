
#include "primesettings.h"
#include "timing.h"
#include "utils.h"
#include <algorithm>
#include <cmath>
#include <vector>

int main(int argc, char *argv[]) {
    auto settings = PrimeSettings{argc, argv};

    auto timing = Timing{"magic"};

    auto numbers = std::vector<bool>(settings.num, true);

    numbers.at(0) = false;
    numbers.at(1) = false;

    for (long i = 2; i < std::sqrt(settings.num); ++i) {
        auto bit = numbers.at(i);

        if (bit) {
            for (long j = i + i; j < settings.num; j += i) {
                numbers.at(j) = false;
            }
        }
    }

    auto numPrimes = std::count(numbers.begin(), numbers.end(), true);

    if (settings.shouldPrintNumebers) {
        for (size_t i = 0; i < numbers.size(); ++i) {
            if (numbers.at(i)) {
                std::cout << i << "\n";
            }
        }
    }

    std::cout << "number of primes: " << numPrimes << std::endl;
}
