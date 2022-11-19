cmake_minimum_required (VERSION 3.5)
project (sudoku-SAT VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)

find_package(minisat REQUIRED)

add_executable(sudoku-cli
    main.cpp
    Solver.cpp
    # Headers for IDEs
    Solver.hpp
    tablero/Tablero.cpp 
    tablero/Tablero.hpp
)
target_link_libraries(sudoku-cli MiniSat::libminisat)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT sudoku-cli)