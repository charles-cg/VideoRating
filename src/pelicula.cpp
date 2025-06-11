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
	cout << " Nombre: " << getNombre();
	cout << " Duracion: " << getDuracion();
	cout << " Genero: " << getGenero();
    cout << " Calificacion: " << getCalificacion() << endl;
}
