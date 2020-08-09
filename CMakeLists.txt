cmake_minimum_required(VERSION 3.15)
project(Simulated_Annealing C)

set(CMAKE_C_STANDARD 99)

add_executable(Simulated_Annealing main.c queue.h queue.c matrix.c matrix.h)