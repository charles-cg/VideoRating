#pragma once
#include <string>
#include "pelicula.h"
#include "episodio.h"

class Datos {
public:
    Datos();
    ~Datos();

    int countLines(std::string filename);

    //metodo 1
    bool cargarDatos();

    //metodo 2
    void displayDatos();

    //metodo 3
    bool buscarVideosGeneral(string searchGenero);

    bool buscarVideosGeneral(float searchCalificacion);

    //metodo 4
    bool buscarEpisodios(string searchNombre, float searchCalificacion);

    //metodo5
    bool buscarPeliculas(float searchCalificacion);

    //metodo 6
    bool calificarVideo(string id, int calificacion);

    bool checkNullptr();
    
private:
    Video **videoArray;

    //metodos carga de datos
    bool loadPeliculaCSV(std::string filename);
    
    bool loadEpisodioCSV(std::string filename);

    unsigned int arraySize;
    unsigned int numeroPeliculas;
    unsigned int numeroEpisodios; 
};
