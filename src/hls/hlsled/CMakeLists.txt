cmake_minimum_required(VERSION 3.14)
project(hlsled)

add_library(piyolib STATIC piyo.cpp)
  # Set the output directory for build artifacts
  set_target_properties(piyolib
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_hls_project(hlsled
  TOP     HlsLED
  VERSION 1.0
  VENDOR  nodamushi
  NAME    "HLS LED Chika"
  PERIOD  10 # 100MHz
  PART    xc7z007sclg400-1
  SOURCES hlsled.cpp
  LINK    foobarlib # ../foobar
  # Test
  TB_SOURCES tb.cpp
  TB_LINK piyolib GTest::gtest
)

add_test(
  NAME test_hlsled
  COMMAND $<TARGET_FILE:test_hlsled>)
