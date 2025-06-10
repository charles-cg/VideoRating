#include <iostream>
#include "datos.h"
#include <fstream>
#include <sstream>

using namespace std;

Datos::Datos() {
	episodioArray = nullptr;
	peliculaArray = nullptr;
	dataSizeEpisodio = 0;
	dataSizePelicula = 0;
}

bool Datos::revisionErroresPelicula(string filename) {
	dataSizePelicula = readLines(filename);
	if(dataSizePelicula == -1) {
		cerr << "No se pudo cargar el data set desde " << filename << "\n";
		return 0;
	}

	cout << "El archivo \"" << filename << "\" tiene: " << dataSizePelicula << " entradas\n";
	peliculaArray = new(nothrow) Pelicula [dataSizePelicula];
	if(peliculaArray == nullptr) {
		cerr << "No hubo memoria para el arreglo creado con datos de " << filename << "\n";
		return 0;
	}

	if(!loadPeliculaCSV(filename, dataSizePelicula)) {
		cerr << "Error al cargar el data set de " << filename << "\n";
		delete [] peliculaArray;
		return 0;
	}
}

bool Datos::revisionErroresEpisodio(string filename) {
	dataSizeEpisodio = readLines(filename);
	if(dataSizeEpisodio == -1) {
		cerr << "No se pudo cargar el data set desde " << filename << "\n";
		return 0;
	}

	cout << "El archivo \"" << filename << "\" tiene: " << dataSizeEpisodio << " entradas\n";
	episodioArray = new(nothrow) Episodio [dataSizeEpisodio];
	if(peliculaArray == nullptr) {
		cerr << "No hubo memoria para el arreglo creado con datos de " << filename << "\n";
		return 0;
	}

	if(!loadPeliculaCSV(filename, dataSizeEpisodio)) {
		cerr << "Error al cargar el data set de " << filename << "\n";
		delete [] episodioArray;
		return 0;
	}
}

bool Datos::loadPeliculaCSV(string filename, unsigned int arraySize) {
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
		Pelicula newPeli;
		stringstream ss(line);
		string cell;
		int campo = 0, errores = 0;

		while (getline(ss, cell, ',')) {
			if (!cell.length())
				errores++;
			switch (campo){
				case 0:
					newPeli.setId(cell);
					break;
				case 1:
					newPeli.setNombre(cell);
					break;
				case 2:
					newPeli.setCalificacion(stod(cell));
					break;
				case 3:
					newPeli.setGenero(cell);
					break;
				case 4:
					newPeli.setDuracion(stod(cell));
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
			peliculaArray[size] = newPeli;
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

bool Datos::loadVideosCSV(string filename, unsigned int arraySize) {
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
		Video newVid;
		stringstream ss(line);
		string cell;
		int campo = 0, errores = 0;

		while (getline(ss, cell, ',')) {
			if (!cell.length())
				errores++;
			switch (campo){
				case 0:
					newVid.setId(cell);
					break;
				case 1:
					newVid.setNombre(cell);
					break;
				case 2:
					newVid.setCalificacion(stod(cell));
					break;
				case 3:
					newVid.setGenero(cell);
					break;
				case 4:
					newVid.setDuracion(stod(cell));
				default:
					errores++;
					break;
			}
			campo++;
		}
		if (errores || campo != VIDEO_ATTRIB_SIZE){
			cout << "Error en la linea: " << line << endl;
			file.close();
			return false;
		}
		if(size < arraySize) {
			videoArray[size] = newVid;
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

bool Datos::loadEpisodioCSV(string filename, unsigned int arraySize) {
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
		Episodio newEpi;
		stringstream ss(line);
		string cell;
		int campo = 0, errores = 0;

		while (getline(ss, cell, ',')) {
			if (!cell.length())
				errores++;
			switch (campo){
				case 0:
					newEpi.setId(cell);
					break;
				case 1:
					newEpi.setNombre(cell);
					break;
				case 2:
					newEpi.setCalificacion(stod(cell));
					break;
				case 3:
					newEpi.setGenero(cell);
					break;
				case 4:
					newEpi.setDuracion(stod(cell));
					break;
				case 5:
					newEpi.setNumeroEpisodio(cell);
					break;
				case 6:
					newEpi.setNumeroTemporada(stod(cell));
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
			episodioArray[size] = newEpi;
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

int Datos::readLines(string filename) {
	ifstream file(filename);
	int lineCount = 0;
	string line;

	if (!file.is_open()) {
		cout << "No se pudo abrir el archivo: " << filename <<endl;
		return 0;
	}
	while (!getline (file, line)) {
		cout << "EL arhcivo no tiene header" << endl;
		file.close();
		return 0;
	}
	file.close();
	return lineCount;
}