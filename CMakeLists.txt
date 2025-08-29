cmake_minimum_required(VERSION 3.30)
project(TiendaVideoJuegos_Luisalejandropp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.github)

add_executable(TiendaVideoJuegos_Luisalejandropp
    .github/main.cpp
    .github/Tienda.cpp
    .github/Tienda.h)
