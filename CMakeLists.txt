cmake_minimum_required(VERSION 3.31)
project(VideoRating2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(VideoRating2
        src/datos.h
        src/episodio.cpp
        src/episodio.h
        src/main.cpp
        src/menu.cpp
        src/menu.h
        src/pelicula.cpp
        src/pelicula.h
        src/video.cpp
        src/video.h)
