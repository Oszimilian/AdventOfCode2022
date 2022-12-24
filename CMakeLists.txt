cmake_minimum_required(VERSION 3.24)
project(AdventOfCode2022 C)

set(CMAKE_C_STANDARD 11)

include_directories(AdventOfCode1/src)

add_executable(AdventOfCode2022
        AdventOfCode1/src/adventOfCode.h
        AdventOfCode1/src/day6.c
        AdventOfCode1/src/day7.c
        AdventOfCode1/src/day8.c
        AdventOfCode1/src/Element.h
        AdventOfCode1/src/LinkedList.c
        AdventOfCode1/src/List.h
        AdventOfCode1/src/main.c
        AdventOfCode1/src/myFile.c
        AdventOfCode1/src/myFile.h
        AdventOfCode1/src/day9.c AdventOfCode1/src/day10.c AdventOfCode1/src/day5.c AdventOfCode1/src/day4.c AdventOfCode1/src/day3.c AdventOfCode1/src/day2.c AdventOfCode1/src/day1.c)
