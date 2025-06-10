#pragma once
#include <string>
#include "pelicula.h"
#include "episodio.h"

class Datos {
public:
    Datos();
    ~Datos();
    bool loadPeliculaCSV(std::string filename, Video* videoArray, unsigned int arraySize);
    int readPeliculaLines(std::string filename);
    bool loadEpisodioCSV(std::string filename, Episodio* arrayEpisodio, unsigned int arraySize);
    int readEpisodioLines(std::string filename);
private:
    int *arrayEpisodio;
    int *arrayPelicula;
};
