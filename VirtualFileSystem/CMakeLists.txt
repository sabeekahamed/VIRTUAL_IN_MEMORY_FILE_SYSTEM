cmake_minimum_required(VERSION 3.18)

# Set the project name and version
project(VirtualFileSystem VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the output directories for build artifacts
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
set(SOURCES
    src/main.cpp
    src/Command.cpp
    src/FileSystem.cpp
    src/CommandFactory.cpp
    src/CommandInvoker.cpp
    # Add additional source files here
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Optionally, link libraries
# target_link_libraries(${PROJECT_NAME} SomeLibrary)

# Add custom compiler flags (optional)
# Example: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
