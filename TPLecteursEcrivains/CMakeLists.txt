cmake_minimum_required(VERSION 4.0.0)

project("TPThreadsLecteursEcrivains")

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include_directories(
    ${CMAKE_SOURCE_DIR}
)

message(${CMAKE_SOURCE_DIR})

set(SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
)

set(EXECUTABLE ${PROJECT_NAME}.exe)
add_executable(${EXECUTABLE} ${SOURCES})

