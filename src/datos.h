#pragma once
#include <string>
#include "pelicula.h"
#include "episodio.h"

class Datos {
public:
    Datos();
    ~Datos();

    //metodos para la carga de datos
    bool loadPeliculaCSV(std::string filename);
    bool loadEpisodioCSV(std::string filename);

    int countLines(std::string filename);

    bool cargarDatos();

    void displayDatos();

    bool calificarEpisodio(string id, int calificacion);
private:
    Video **videoArray;


    unsigned int arraySize;
    unsigned int numeroPeliculas;
    unsigned int numeroEpisodios; 
};
