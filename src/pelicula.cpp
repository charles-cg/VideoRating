#include <iostream>
#include "pelicula.h"
#include <fstream>
#include <sstream>

using namespace std;

Pelicula::Pelicula() {

}

Pelicula::~Pelicula() {
    
}

void Pelicula::printData() {
    cout << "Pelicula: ";
	cout << "ID: " << getId();
	cout << "Nombre: " << getNombre();
	cout << "Duracion: " << getDuracion();
	cout << "Genero: " << getGenero();
    cout << "Calificacion: " << getCalificacion();
}

bool loadPeliculas(string filename, unsigned int arraySIze) {
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
					newPeli.setDuracion();
				default:
					errores++;
					break;
				}
			campo++;
			}
		if (errores || campo != /*CONSTANTE*/){
			cout << "Error en la linea: " << line << endl;
			file.close();
			return false;
		}
		if(size < arraySize) {
			partArray[size] = newPeli;
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
int readPeliculasLines(string filename) {
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