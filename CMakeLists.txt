cmake_minimum_required(VERSION 3.20.0)
cmake_policy(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

project(BetoneiraEngine VERSION 0.1)
add_executable(BetoneiraEngine "${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/engine/engine.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/engine/window/window.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/engine/shared/shared.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/engine/glad.c" "${CMAKE_CURRENT_SOURCE_DIR}/engine/shader/shader.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/engine/file/file.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/engine/color/color.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/engine/input/input.cpp")

target_link_libraries(BetoneiraEngine glfw3)
target_link_libraries(BetoneiraEngine OpenGL::GL)

target_include_directories(BetoneiraEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/engine" "${CMAKE_CURRENT_SOURCE_DIR}/include")