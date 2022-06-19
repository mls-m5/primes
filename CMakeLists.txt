
cmake_minimum_required(VERSION 3.23)
project(primes)

add_executable(
    benchmark
    src/benchmark.cpp
    )


add_executable(
    naive
    src/1-naive.cpp
    )

add_executable(
    basic
    src/2-basic-optimization.cpp
    )

add_executable(
    magic
    src/3-elimination-magic.cpp
    )

target_compile_features(benchmark PRIVATE cxx_std_17)
target_compile_features(naive PRIVATE cxx_std_17)
target_compile_features(basic PRIVATE cxx_std_17)
target_compile_features(magic PRIVATE cxx_std_17)

