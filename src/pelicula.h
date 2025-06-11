#pragma once
#include "video.h"

#define PELICULA_ATTRIB_SIZE 4

class Pelicula : public Video {
public:
    Pelicula();
    ~Pelicula();

    void printData() override;
};