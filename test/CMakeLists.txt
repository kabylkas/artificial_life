cmake_minimum_required(VERSION 3.0)

project(test_alife)

set (FLAGS "-std=c++1z -g -O3")
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${FLAGS})
set(SRC_DIR ../src)
include_directories(${SRC_DIR})

set(TEST_H
  ./test_world.h
  ./test_runner.h
)

set(ALIFE_H
  ${SRC_DIR}/SupportTypes.h
  ${SRC_DIR}/World.h
)

set(ALIFE_CPP
  ${SRC_DIR}/World.cpp
)

add_executable(test_alife test_alife.cpp ${TEST_H} ${ALIFE_H} ${ALIFE_CPP})
