cmake_minimum_required (VERSION 3.0.2)
project(game_lab LANGUAGES CXX)

# Project directories
set (PROJECT_INCLUDE_DIR "$(PROJECT_SOURCE_DIR)/inc")
set (PROJECT_SRC_DIR "$(PROJECT_SOURCE_DIR)/src")
set (PROJECT_ASSETS_DIR "$(PROJECT_SOURCE_DIR)/assets")

# List of files
file(GLOB_RECURSE SOURCES "${PROJECT_SRC_DIR}/*.cpp"
                          "${PROJECT_SRC_DIR}/*.c")

# Include headers
include_directories("${PROJECT_INCLUDE_DIR}")

# Compilation flags
set(COMPILE_FLAGS "")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++11 -W -Wall -pedantic -std=c++11 -Wshadow -O2 -g")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++11 -W -Wall -pedantic -std=c++11 -Wshadow -O2 -g")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} /Wall")
endif()

# CMake compilation flags redefinition
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

# Add engine
set (PROJECT_ENGINE_DIR "${PROJECT_SOURCE_DIR}/engine")
add_subdirectory(${PROJECT_ENGINE_DIR})
include_directories(${ENGINE_INCLUDE_DIR})

# Executable
add_executable(game_lab ${SOURCES})

target_link_libraries(game_lab
                      engine
                      SDL2 SDL2_image SDL2_ttf SDL2_mixer)

# Copy assets folder to build
add_custom_command(TARGET game_lab POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
${PROJECT_ASSETS_DIR} ${CMAKE_BINARY_DIR}/assets)
