cmake_minimum_required(VERSION 3.15)
project(PA6)

set(CMAKE_CXX_STANDARD 14)

add_executable(PA6 main.cpp PendingProcess.h Scheduler.cpp Scheduler.h)