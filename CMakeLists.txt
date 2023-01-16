cmake_minimum_required(VERSION 3.14)
project(study)

# Download
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include (GoogleTest)

FetchContent_Declare(
  vivado_cmake_module
  GIT_REPOSITORY  https://github.com/nodamushi/vivado_cmake_module.git
  GIT_TAG v0.0.2
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
