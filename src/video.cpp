#include <iostream>
#include "video.h"

using namespace std;

Video::Video() {
    duracion = 0;
    calificacion = 0;
    numeroCalificaciones = 0;
    sumaCalificacion = 0;
}

Video::~Video() {
    
}

//metodos set
void Video::setId(string newId) {
    id = newId;
}

void Video::setNombre(string newName) {
    nombre = newName;
}

void Video::setDuracion(float newDuracion) {
    duracion = newDuracion;
}

void Video::setGenero(string newGenero) {
    genero = newGenero;
}

void Video::setCalificacion(float newCalificacion) {
    numeroCalificaciones++;
    sumaCalificacion += newCalificacion;
    calificacion = sumaCalificacion / numeroCalificaciones;
}

//metodos get
string Video::getId() {
    return id;
}

string Video::getNombre() {
    return nombre;
}
float Video::getDuracion() {
    return duracion;
}
string Video::getGenero() {
    return genero;
}

float Video::getCalificacion() { //revisar ya que se necesita un promedio
    return calificacion;
}

//
void Video::printData() {
    cout << "Video: ";
	cout << "ID: " << id;
	cout << "Nombre: " << nombre;
	cout << "Duracion: " << duracion;
	cout << "Genero: " << genero << endl;
}