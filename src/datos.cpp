#include <iostream>
#include "datos.h"
#include <fstream>
#include <sstream>

#define PELICULA_CSV "movies.csv"
#define EPISODIO_CSV "series.csv"

using namespace std;

//Constructor
Datos::Datos() {
	videoArray = nullptr;
}

//Destructor
Datos::~Datos() {
	if (videoArray) {
		delete [] videoArray;
		videoArray = nullptr;
	}
}

//get methods

//metodo para contar lineas
int Datos::countLines(string fileName) {
    ifstream    file(fileName);
    int         lineCount = 0;
    string      line;

    // Contar la cantidad de líneas en el archivo csv
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return -1;
    }

    // skip header
    if(!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return -1;
    }

    // Contar lineas 
    while(getline(file, line)) {
        lineCount++;    
    }

    file.close();
    return(lineCount);
}

//metodos para la carga de datos
bool Datos::loadPeliculaCSV(string filename) {
	ifstream file(filename);
	string line;
	unsigned int size = 0;

	if (!file.is_open()) {
		cout << "No se pudo abrir el archivo: " << filename <<endl;
		return false;
	}
	if (!getline (file, line)) {
		cout << "El archivo no tiene header" << endl;
		return false;
	}
	cout << "Archivo abierto"<<endl;
	//Aquí preguntar a Artemio si copiamos parte por parte el código
	while (getline (file, line)) {
		Pelicula *newPeli = new Pelicula();
		stringstream ss(line);
		string cell;
		int campo = 0, errores = 0;

		while (getline(ss, cell, ',')) {
			if (!cell.length())
				errores++;
			switch (campo){
				case 0:
					newPeli->setId(cell);
					break;
				case 1:
					newPeli->setNombre(cell);
					break;
				case 2:
					newPeli->setDuracion(stoi(cell));
					break;					
				case 3:
					newPeli->setGenero(cell);
					break;
				default:
					errores++;
					break;
				}
			campo++;
			}
		if (errores || campo != PELICULA_ATTRIB_SIZE){
			cout << "Error en la linea: " << line << endl;
			file.close();
			return false;
		}
		if(size < arraySize) {
			videoArray[size] = newPeli;
			size++;
		}
		else {
			cout << "Error, el arreglo es muy pequeño" << endl;
			file.close();
			return false;
		}
	}
	file.close();
	return true;
}

bool Datos::loadEpisodioCSV(string filename) {
	ifstream file(filename);
	string line;
	unsigned int size = numeroPeliculas;

	if (!file.is_open()) {
		cout << "No se pudo abrir el archivo: " << filename <<endl;
		return false;
	}
	if (!getline (file, line)) {
		cout << "El archivo no tiene header" << endl;
		return false;
	}
	cout << "Archivo abierto"<<endl;
	//Aquí preguntar a Artemio si copiamos parte por parte el código
	while (getline (file, line)) {
		Episodio *newEpi = new Episodio();
		stringstream ss(line);
		string cell;
		int campo = 0, errores = 0;

		while (getline(ss, cell, ',')) {
			if (!cell.length())
				errores++;
			switch (campo){
				case 0:
					newEpi->setId(cell);
					break;
				case 1:
					newEpi->setNombre(cell);
					break;
				case 2:
					newEpi->setDuracion(stoi(cell));
					break;					
				case 3:
					newEpi->setGenero(cell);
					break;
				case 4:
					newEpi->setNombreEpisodio(cell);
					break;
				case 5:
					newEpi->setNumeroTemporada(stoi(cell));
					break;
				default:
					errores++;
					break;
			}
			campo++;
		}
		if (errores || campo != EPISODIO_ATTRIB_SIZE){
			cout << "Error en la linea: " << line << endl;
			file.close();
			return false;
		}
		if(size < arraySize) {
			videoArray[size] = newEpi;
			size++;
		}
		else {
			cout << "Error, el arreglo es muy pequeño" << endl;
			file.close();
			return false;
		}
	}
	file.close();
	return true;
}

bool Datos::cargarDatos() {
	numeroPeliculas = countLines(PELICULA_CSV);
	if(numeroPeliculas == -1) {
		cerr << "No se pudo cargar el data set desde " << PELICULA_CSV << "\n";
		return false;
	}
	
	numeroEpisodios = countLines(EPISODIO_CSV);
	if(numeroEpisodios == -1) {
		cerr << "No se pudo cargar el data set desde " << EPISODIO_CSV << "\n";
		return false;
	}	

	cout << "El archivo \"" << PELICULA_CSV << "\" tiene: " << numeroPeliculas << " peliculas\n";
	cout << "El archivo \"" << EPISODIO_CSV << "\" tiene: " << numeroEpisodios << " episodio\n";

	arraySize = numeroPeliculas + numeroEpisodios;

	videoArray = new(nothrow) Video *[arraySize];

	if(videoArray == nullptr) {
		cerr << "No hubo memoria para el arreglo creado con datos de " << PELICULA_CSV << "y " << EPISODIO_CSV << "\n";
		return false;
	}

	if(!loadPeliculaCSV(PELICULA_CSV)) {
		cerr << "Error al cargar el data set de " << PELICULA_CSV << "\n";
		delete [] videoArray;
		videoArray = nullptr;
		return false;
	}

	if(!loadEpisodioCSV(EPISODIO_CSV)) {
		cerr << "Error al cargar el data set de " << EPISODIO_CSV << "\n";
		delete [] videoArray;
		videoArray = nullptr;
		return false;
	}
	return true;
}

//metodos para el menu
void Datos::displayDatos() {
    for (unsigned int i = 0; i < arraySize; i++) {
        videoArray[i]->printData();
    }
}