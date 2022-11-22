cmake_minimum_required(VERSION 3.5)
project(foo-sat LANGUAGES CXX)

add_executable(foo main.cpp SolverOwn.cpp SolverOwn.hpp Tablero.cpp Tablero.hpp)

add_subdirectory(minisat)
target_link_libraries(foo MiniSat::libminisat)
