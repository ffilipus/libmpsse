cmake_minimum_required(VERSION 3.0)

project(mpsse)

set(libsrc src/fast.c src/mpsse.c src/support.c) 
add_library(objlib OBJECT ${libsrc})
set_property(TARGET ${objlib} PROPERTY POSITION_INDEPENDENT_CODE 1)
# add_library(libmpsse SHARED $<TARGET_OBJECTS:objlib>)
add_library(mpsse STATIC $<TARGET_OBJECTS:objlib>)
target_link_libraries(mpsse ftdi1)
add_definitions(-DPACKAGE_VERSION=1)
