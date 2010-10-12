cmake_minimum_required(VERSION 2.6)

project(chimpanse)
# The version number.
set (OI_MAJOR 0)
set (OI_MINOR 1)
set (OI_PATCH 1)

MESSAGE(STATUS "Configuring chimpanse ${OI_MAJOR}.${OI_MINOR}.${OI_PATCH}")

find_package(Qt4 REQUIRED) # find and setup Qt4 for this project

# tell cmake to process CMakeLists.txt in that subdirectory
add_subdirectory(src)
