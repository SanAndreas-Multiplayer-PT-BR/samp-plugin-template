cmake_minimum_required (VERSION 3.8)

project ("samp-plugin-template")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib/cmake-modules")

set(LIB "${CMAKE_SOURCE_DIR}/lib")
set(SDK "${CMAKE_SOURCE_DIR}/lib/SDK")
set(RAKNET "${CMAKE_SOURCE_DIR}/lib/raknet")

add_definitions("-DSUBHOOK_STATIC")
add_subdirectory ("src")