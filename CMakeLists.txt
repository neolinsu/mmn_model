cmake_minimum_required (VERSION 3.1)
SET(CMAKE_CXX_FLAGS "-g -Wall -O2")
add_compile_options(-std=c++11)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

ADD_EXECUTABLE(mmn_model ${SRC})
