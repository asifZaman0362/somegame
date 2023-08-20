cmake_minimum_required(VERSION 3.15)
project(game)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

find_package(SFML 2.5 COMPONENTS window system graphics audio network REQUIRED)

include_directories(inc)

set(SOURCE_FILES src/main.cc)
add_executable(game ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} sfml-window sfml-system sfml-graphics sfml-audio sfml-network)
