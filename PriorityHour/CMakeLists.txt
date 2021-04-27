cmake_minimum_required(VERSION 3.17)
project(PriorityHour C)

set(CMAKE_C_STANDARD 11)

add_executable(PriorityHour main.c Patient.c Patient.h enums.h Date.c Date.h Utility.c Utility.h)