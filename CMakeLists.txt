cmake_minimum_required(VERSION 3.16)
project(GameSkeleton VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

add_executable(GameSkeleton
  Core/Src/main.cpp
  Core/Src/Config.cpp
  Core/Src/Game.cpp
)

target_include_directories(GameSkeleton PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc
)

target_link_libraries(GameSkeleton PRIVATE raylib)

# Warnings (helps a lot early)
if (MSVC)
  target_compile_options(GameSkeleton PRIVATE /W4)
else()
  target_compile_options(GameSkeleton PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Copy Assets next to the exe (so relative asset paths work)
add_custom_command(TARGET GameSkeleton POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${CMAKE_CURRENT_SOURCE_DIR}/Assets
          $<TARGET_FILE_DIR:GameSkeleton>/Assets
)
