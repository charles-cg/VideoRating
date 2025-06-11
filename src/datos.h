#pragma once
#include <string>
#include "pelicula.h"
#include "episodio.h"

class Datos {
public:
    Datos();
    ~Datos();

    //metodos para la carga de datos

    int countLines(std::string filename);

    bool cargarDatos();

    void displayDatos();

    bool calificarVideo(string id, int calificacion);
    
    bool buscarEpisodios(string searchId, float searchCalificacion);
private:
    Video **videoArray;

    bool loadPeliculaCSV(std::string filename);
    
    bool loadEpisodioCSV(std::string filename);

    unsigned int arraySize;
    unsigned int numeroPeliculas;
    unsigned int numeroEpisodios; 
};
