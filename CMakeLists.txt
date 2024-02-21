cmake_minimum_required(VERSION 3.20.0)

project(AscImg)

set(SRC
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    )

add_executable(${PROJECT_NAME} ${SRC})

find_package(fmt)

target_link_libraries(${PROJECT_NAME} fmt::fmt)
