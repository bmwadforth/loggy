cmake_minimum_required(VERSION 3.16)
project(audite C)

set(CMAKE_C_STANDARD 11)

add_executable(audite main.c include/keystroke/keystroke.h src/keystroke/keystroke.c)