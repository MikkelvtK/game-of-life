cmake_minimum_required(VERSION 3.30)
project(game_of_life C)

set(CMAKE_C_STANDARD 17)

include(ctest)

set(UNITY_DIR ${CMAKE_SOURCE_DIR}/lib/unity)

add_library(unity STATIC ${UNITY_DIR}/unity.c)
target_include_directories(unity PUBLIC ${UNITY_DIR})

add_executable(game_of_life main.c)

add_executable(game_of_life_app ${CMAKE_SOURCE_DIR}/test/test_game_of_life.c)
target_link_libraries(game_of_life_app unity)
add_test(game_of_life_test game_of_life_app)
