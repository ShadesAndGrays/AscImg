cmake_minimum_required(VERSION 3.20.0)

project(AscImg)

set (CMAKE_EXPORT_COMPILE_COMMANDS on)

include_directories(include)

set(SRC
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/braille.cpp
    )

add_executable(${PROJECT_NAME} ${SRC})

find_package(argparse)
target_link_libraries(${PROJECT_NAME} argparse::argparse)
