#pragma once
#include <string>
#include "pelicula.h"
#include "episodio.h"

class Datos {
public:
    Datos();
    ~Datos();
    bool loadPeliculaCSV(std::string filename, unsigned int arraySize);
    int readLines(std::string filename);
    bool loadEpisodioCSV(std::string filename, unsigned int arraySize);
    bool loadVideosCSV(std::string filename, unsigned int arraySize);
    bool revisionErroresPelicula(string filename);
    bool revisionErroresEpisodio(string filename);
    Episodio *getEpisodioArray();
    Pelicula *getPeliculaArray();
private:
    Episodio *episodioArray;
    Pelicula *peliculaArray;
    Video *videoArray;
    int dataSizePelicula;
    int dataSizeEpisodio;
};
