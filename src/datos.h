#pragma once
#include <string>
#include "pelicula.h"
#include "episodio.h"

class Datos {
public:
    Datos();
    ~Datos();
    bool loadPeliculaCSV(std::string filename, unsigned int arraySize);
    int readPeliculaLines(std::string filename);
    bool loadEpisodioCSV(std::string filename, unsigned int arraySize);
    int readEpisodioLines(std::string filename);
    bool loadVideosCSV(std::string filename, unsigned int arraySize);
    int readVideosLines(std::string filename);
private:
    Episodio *episodioArray;
    Pelicula *peliculaArray;
    Video *videoArray;
};
