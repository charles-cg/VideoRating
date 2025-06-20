#include <iostream>
#include "episodio.h"

using namespace std;

Episodio::Episodio() {
    numeroTemporada = 0;
}

Episodio::~Episodio() {

}

void Episodio::setNombreEpisodio(string newNombreEpisodio) {
    nombreEpisodio = newNombreEpisodio;
}

void Episodio::setNumeroTemporada(int newNumeroTemporada) {
    numeroTemporada = newNumeroTemporada;
}

string Episodio::getNombreEpisodio() {
	return nombreEpisodio;
}

int Episodio::getNumeroTemporada() {
	return numeroTemporada;
}

void Episodio::printData() {
    cout << "Episodio: ";
	cout << "ID: " << getId();
	cout << " Nombre: " << getNombre();
	cout << " Duracion: " << getDuracion();
	cout << " Genero: " << getGenero();
	cout << " Titulo: " << nombreEpisodio;
	cout << " Temporada: " << numeroTemporada; 
	cout << " Calificacion: " << getCalificacion() << endl;  
}