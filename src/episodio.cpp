#include <iostream>
#include "episodio.h"

using namespace std;

void Episodio::setNumeroEpisodio(string newNombreEpisodio) {
    nombreEpisodio = newNombreEpisodio;
}

void Episodio::setNumeroTemporada(int newNumeroTemporada) {
    numeroTemporada = newNumeroTemporada;
}

void Episodio::printData() {
    cout << "Video: ";
	cout << "ID: " << getId();
	cout << "Nombre: " << getNombre();
	cout << "Duracion: " << getDuracion();
	cout << "Genero: " << getGenero();
	cout << "Titulo: " << nombreEpisodio;
	cout << "Temporada: " << numeroTemporada << endl;   
}