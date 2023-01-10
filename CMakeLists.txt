cmake_minimum_required(VERSION 3.14)
project(study)
set(CMAKE_CXX_STANDARD 11)

# Download
include(FetchContent)
FetchContent_Declare(
  vivado_cmake_module
  GIT_REPOSITORY  https://github.com/nodamushi/vivado_cmake_module.git
  GIT_TAG v0.0.1
)
FetchContent_MakeAvailable(vivado_cmake_module)
list(APPEND CMAKE_MODULE_PATH ${vivado_cmake_module_SOURCE_DIR})

# find package
find_package(HLS)
find_package(Vivado)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(RTL_DIR ${SRC_DIR}/rtl)
set(CONSTRAINT_DIR ${SRC_DIR}/constraint)
set(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(BUILD_HLS_DIR ${BUILD_DIR}/src/hls)

add_subdirectory(src)
add_subdirectory(vivado)
