cmake_minimum_required(VERSION 3.8)
project(OrgaTarea1_master)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Evaluador.cpp
        Evaluador.h
        main.cpp
        Mascota.cpp
        Mascota.h)

add_executable(OrgaTarea1_master ${SOURCE_FILES})