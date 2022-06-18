
cmake_minimum_required(VERSION 3.23)
project(primes)

add_executable(
    naive
    src/1-naive.cpp
    )


target_compile_features(naive PRIVATE cxx_std_17)
