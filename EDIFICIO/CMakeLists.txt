cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp cmake-build-debug/Administracion.cpp cmake-build-debug/Administracion.h cmake-build-debug/Propietario.cpp cmake-build-debug/Propietario.h cmake-build-debug/Propiedad.cpp cmake-build-debug/Propiedad.h)
