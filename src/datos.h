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

    //metodo 1
    bool cargarDatos();

    //metodo 2
    void displayDatos();

    //metodo 3


    //metodo 4
    bool buscarEpisodios(string searchId, float searchCalificacion);

    //metodo5
    bool buscarPeliculas(float searchCalificacion);

    //metodo 6
    bool calificarVideo(string id, int calificacion);
    
private:
    Video **videoArray;

    bool loadPeliculaCSV(std::string filename);
    
    bool loadEpisodioCSV(std::string filename);

    unsigned int arraySize;
    unsigned int numeroPeliculas;
    unsigned int numeroEpisodios; 
};
