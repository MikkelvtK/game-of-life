cmake_minimum_required(VERSION 3.30)
project(game_of_life C)

set(CMAKE_C_STANDARD 17)

# VARIABLES
set(RAYLIB_DIR ${PROJECT_SOURCE_DIR}/lib/raylib)

# RAYLIB
find_package(raylib)

# APPLICATION
add_executable(game_of_life
        src/main.c
        src/game_of_life.c
        src/grid.c
        src/menu.c
        src/inputs.c)

target_include_directories(game_of_life PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(game_of_life PRIVATE raylib)
target_include_directories(game_of_life PRIVATE ${RAYLIB_DIR}/include)

