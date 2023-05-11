cmake_minimum_required(VERSION 3.25)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tetris main.cpp windowset.h windowset.cpp interactive.cpp interactive.h consoleset.cpp consoleset.h element.cpp element.h block.cpp block.h blockgroup.cpp blockgroup.h randomgen.cpp randomgen.h)

