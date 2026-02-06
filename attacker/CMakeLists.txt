cmake_minimum_required(VERSION 3.5)

project(AttackerApp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add threading library
find_package(Threads REQUIRED)

include_directories(include)
include_directories(../common/include)

# Common sources
file(GLOB_RECURSE COMMON_SOURCES
    "src/model/*.cpp"
    "src/model/*.h"
    "src/controller/*.cpp"
    "src/controller/*.h"
    "src/commands/*.cpp"
    "src/commands/*.h"
    "../common/src/*.cpp"
)

# CLI Target (The only target now)
add_executable(AttackerAppCLI
    src/mainCli.cpp
    src/view/ConsoleView.cpp
    src/view/ConsoleView.h
    ${COMMON_SOURCES}
)

# Link threads (required for std::thread)
target_link_libraries(AttackerAppCLI Threads::Threads)
