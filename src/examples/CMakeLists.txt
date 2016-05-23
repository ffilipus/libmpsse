cmake_minimum_required(VERSION 3.0)

project(bitbang)

add_executable(bitbang bitbang.c)
add_executable(gpio gpio.c)
#find_library (MPSSE NAMES libmpsse mpsse)
#find_library (FTDI1 ftdi1)
#set(CMAKE_STANDARD_LIBRARIES MPSSE FTDI1)
target_link_libraries (bitbang mpsse ftdi1)
target_link_libraries (gpio mpsse ftdi1)
add_definitions(-DLIBFTDI1=1)
