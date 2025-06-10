#include <iostream>
#include "datos.h"
#include <fstream>
#include <sstream>

using namespace std;

bool Datos::loadPeliculaCSV(string filename, unsigned int arraySIze) {
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
			}
		}

	}
}