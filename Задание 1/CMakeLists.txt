cmake_minimum_required(VERSION 4.0.2)
project(oop_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop_3 main.cpp
        Figures.cpp
        Figures.h
        Circle.cpp
        Circle.h
        Rectangle.cpp
        Rectangle.h
        Triangle.h
        Triangle.cpp
        Trapezoid.h
        Trapezoid.cpp)
