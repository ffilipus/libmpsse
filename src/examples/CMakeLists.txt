cmake_minimum_required(VERSION 3.0)

project(bitbang)

add_executable(bitbang bitbang.c)
add_executable(gpio gpio.c)
add_executable(i2ceeprom i2ceeprom.c)
add_executable(ds1305 ds1305.c)
add_executable(spiflash spiflash.c)
add_executable(spiflashfast spiflashfast.c)
add_executable(i2cbmp180 i2cbmp180.cpp)
#find_library (MPSSE NAMES libmpsse mpsse)
#find_library (FTDI1 ftdi1)
#set(CMAKE_STANDARD_LIBRARIES MPSSE FTDI1)
target_link_libraries (bitbang mpsse ftdi1)
target_link_libraries (gpio mpsse ftdi1)
target_link_libraries (i2ceeprom mpsse ftdi1)
target_link_libraries (ds1305 mpsse ftdi1)
target_link_libraries (spiflash mpsse ftdi1)
target_link_libraries (spiflashfast mpsse ftdi1)
target_link_libraries (i2cbmp180 mpsse ftdi1)
add_definitions(-DLIBFTDI1=1)
