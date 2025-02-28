cmake_minimum_required(VERSION 3.30)
project(game_of_life C)

set(CMAKE_C_STANDARD 17)

include(ctest)

# VARIABLES
set(UNITY_DIR ${CMAKE_SOURCE_DIR}/lib/unity)
set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/lib/raylib)

# UNITY
add_library(unity STATIC ${UNITY_DIR}/unity.c)
target_include_directories(unity PUBLIC ${UNITY_DIR})

# RAYLIB
find_package(raylib)

# APPLICATION
add_executable(game_of_life main.c
                    src/game_of_life.c)
target_include_directories(game_of_life PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(game_of_life raylib)
target_include_directories(game_of_life PUBLIC ${RAYLIB_DIR}/include)

# TEST EXECUTABLES
add_executable(game_of_life_app ${CMAKE_SOURCE_DIR}/test/test_game_of_life.c
                    src/game_of_life.c)
target_include_directories(game_of_life_app PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(game_of_life_app unity)
target_link_libraries(game_of_life_app raylib)
target_include_directories(game_of_life_app PUBLIC ${RAYLIB_DIR}/include)
add_test(game_of_life_test game_of_life_app)
