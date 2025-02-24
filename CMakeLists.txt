cmake_minimum_required(VERSION 3.30)
project(game_of_life C)

set(CMAKE_C_STANDARD 17)

include(ctest)

set(UNITY_DIR ${CMAKE_SOURCE_DIR}/lib/unity)
set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/lib/raylib)

add_library(unity STATIC ${UNITY_DIR}/unity.c)
target_include_directories(unity PUBLIC ${UNITY_DIR})

find_package(raylib)

add_executable(game_of_life main.c
                    src/game_of_life.c)
target_include_directories(game_of_life PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(game_of_life raylib)
target_include_directories(game_of_life PUBLIC ${RAYLIB_DIR}/include)

add_executable(game_of_life_app ${CMAKE_SOURCE_DIR}/test/test_game_of_life.c)
target_link_libraries(game_of_life_app unity)
add_test(game_of_life_test game_of_life_app)
