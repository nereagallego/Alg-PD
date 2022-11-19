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

# set the root directory as ${CMAKE_CURRENT_SOURCE_DIR} which is a
# CMAKE build-in function to return the current dir where your CMakeLists.txt is. 
# Specifically, it is "<your-path>/App/"
set(APP_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# set your 3 other root dirs, i.e. foo, main and test under app/src.
set(APP_ROOT_TABLERO_DIR ${APP_ROOT_DIR}/tablero)
set(APP_ROOT_MINISAT_DIR ${APP_ROOT_DIR}/minisat)

# set your include paths into "SHARED_INCLUDES" variable.
set(SHARED_INCLUDES
                ${APP_ROOT_TABLERO_DIR}

                ${APP_ROOT_MINISAT_DIR}
                ${APP_ROOT_MINISAT_DIR}/build
                ${APP_ROOT_MINISAT_DIR}/CMake
                ${APP_ROOT_MINISAT_DIR}/doc
                ${APP_ROOT_MINISAT_DIR}/jobs
                ${APP_ROOT_MINISAT_DIR}/minisat
                ${APP_ROOT_MINISAT_DIR}/tests

# This function will have effect to all the downstream cmakelist files. 
include_directories(${SHARED_INCLUDES})


# remember to include downstream cmakelist files for foo, main and test.
add_subdirectory(${APP_ROOT_TABLERO_DIR} bin-dir)
add_subdirectory(${APP_ROOT_MINISAT_DIR} bin-dir)