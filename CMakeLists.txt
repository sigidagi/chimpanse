cmake_minimum_required(VERSION 2.6)

PROJECT(OiChimpanse CXX)

# The version number.
set (OI_MAJOR 0)
set (OI_MINOR 1)
set (OI_PATCH 1)

MESSAGE(STATUS "Configuring OiChimpanse ${OI_MAJOR}.${OI_MINOR}.${OI_PATCH}")

SET(CMAKE_CXX_FLAGS "-g -Wall ")
#SET(CMAKE_CXX_FLAGS "-std=c++0x")

FILE(GLOB folder_source *.cpp)
FILE(GLOB folder_header *.h)
SOURCE_GROUP("Source files" FILES ${folder_source})
SOURCE_GROUP("Header files" FILES ${folder_header})

ADD_EXECUTABLE(oichimp ${folder_source})
