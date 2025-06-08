#include <iostream>
#include "video.h"

Video::Video() {
    duracion = 0;
}

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
    calificacion = newCalificacion; //reviasar despues ya que buscamos el promedio
}

void Video::printData() {

}