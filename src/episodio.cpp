#include <iostream>
#include "episodio.h"

using namespace std;

Episodio::Episodio() {
    numeroTemporada = 0;
}

Episodio::~Episodio() {

}

void Episodio::setNumeroEpisodio(string newNombreEpisodio) {
    nombreEpisodio = newNombreEpisodio;
}

void Episodio::setNumeroTemporada(int newNumeroTemporada) {
    numeroTemporada = newNumeroTemporada;
}

void Episodio::printData() {
    cout << "Episodio: ";
	cout << "ID: " << getId();
	cout << "Nombre: " << getNombre();
	cout << "Duracion: " << getDuracion();
	cout << "Genero: " << getGenero();
	cout << "Titulo: " << nombreEpisodio;
	cout << "Temporada: " << numeroTemporada; 
	cout << "Calificacion: " << getCalificacion() << endl;  
}