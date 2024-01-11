cmake_minimum_required(VERSION 3.20.0)
cmake_policy(VERSION 3.20)

project(BetoneiraEngine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(BetoneiraEngine SHARED "${CMAKE_CURRENT_SOURCE_DIR}/engine.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/window/window.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/shared/shared.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/glad.c" "${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/file/file.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/color/color.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/input/input.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/random/random.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/os/os.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/math/vector/vector.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/math/matrix/matrix.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/time/time.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/graphics/graphics.cpp")

target_link_libraries(BetoneiraEngine glfw3)
target_link_libraries(BetoneiraEngine OpenGL::GL)
target_link_libraries(BetoneiraEngine Boost::system Boost::filesystem)

target_include_directories(BetoneiraEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")