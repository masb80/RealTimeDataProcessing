cmake_minimum_required(VERSION 2.8.4)
project(KalmanFilter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EIGEN_INC_DIR /usr/local/include/eigen3/)
include_directories(${EIGEN_INC_DIR})

set(SOURCE_FILES Kalman.cxx main.cxx)
add_executable(kalman ${SOURCE_FILES})
