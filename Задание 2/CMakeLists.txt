cmake_minimum_required(VERSION 4.0)
project(_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(_2
        main.cpp
        Animal.h
        Fish.h
        Fish.cpp
        Bird.h
        Bird.cpp
        FlyingBird.h
        FlyingBird.cpp
)
