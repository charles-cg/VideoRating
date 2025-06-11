#include <iostream>
#include "datos.h"
#include "menu.h"
#include "episodio.h"
#include "pelicula.h"

#define PELICULA_CSV "movies.csv"
#define EPISODE_CSV "series.csv"

int main() {
    string episodioCSV = EPISODE_CSV;
    string peliculaCSV = PELICULA_CSV;

    Datos data;

    data.revisionErroresEpisodio(episodioCSV);
    data.revisionErroresPelicula(peliculaCSV);

    Pelicula *datosPelicula = data.getPeliculaArray();
    Episodio *datosEpisodio = data.getEpisodioArray();

    datosPelicula[2].printData();


    return 0;
}