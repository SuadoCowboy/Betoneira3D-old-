cmake_minimum_required(VERSION 3.20.0)
cmake_policy(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

project(BetoneiraEngine VERSION 0.1)
add_executable(BetoneiraEngine "src/test/main.cpp" "src/engine/engine.cpp" "src/engine/window/window.cpp" "src/engine/shared/shared.cpp" "src/engine/glad.c" "src/engine/shader/shader.cpp" "src/engine/file/file.cpp")

target_link_libraries(BetoneiraEngine glfw3)
target_link_libraries(BetoneiraEngine OpenGL::GL)

target_include_directories(BetoneiraEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/engine" "${CMAKE_CURRENT_SOURCE_DIR}/include")