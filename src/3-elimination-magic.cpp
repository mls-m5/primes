
#include "primesettings.h"
#include "timing.h"
#include <algorithm>
#include <vector>

int main(int argc, char *argv[]) {
    auto settings = PrimeSettings{argc, argv};

    auto timing = Timing{"magic"};

    auto numbers = std::vector<bool>(settings.num, true);

    for (long i = 2; i < settings.num; ++i) {
        auto bit = numbers.at(i);

        if (bit) {
            for (long j = i + i; j < settings.num; j += i) {
                numbers.at(j) = false;
            }
        }
    }

    auto numPrimes = std::count(numbers.begin(), numbers.end(), 0);

    std::cout << "number of primes: " << numPrimes << std::endl;
}
