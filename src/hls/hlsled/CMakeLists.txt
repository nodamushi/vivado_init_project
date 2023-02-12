cmake_minimum_required(VERSION 3.14)
project(hlsled)

# library sample

add_hls_project(hlsled
  TOP     HlsLED
  VERSION 1.0
  VENDOR  nodamushi
  NAME    "HLS LED Chika"
  PERIOD  10 # 100MHz
  PART    xc7z007sclg400-1
  SOURCES hlsled.cpp
  LINK    foobarlib # ../foobar header only library sample
  # Test
  CTEST
  TB_SOURCES tb.cpp
)
