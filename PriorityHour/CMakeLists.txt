cmake_minimum_required(VERSION 3.17)
project(PriorityHour C)

set(CMAKE_C_STANDARD 11)

add_executable(PriorityHour main.c Patient/Patient.c Patient/Patient.h enums.h Date/Date.c Date/Date.h Utility/Utility.h BinarySearchTree/BST.c BinarySearchTree/BST.h Reservation/Reservation.c Reservation/Reservation.h Menu/Menu.c Menu/Menu.h)