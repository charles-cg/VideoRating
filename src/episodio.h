#pragma once
#include "video.h"

#define EPISODIO_ATTRIB_SIZE 6

class Episodio : public Video {
private:
    string nombreEpisodio;
    int numeroTemporada;
public:
    Episodio();
    ~Episodio();
    
    void setNombreEpisodio(string newNombreEpisodio);
    void setNumeroTemporada(int newNumeroTemporada);

    string getNombreEpisodio();
    int getNumeroTemporada();
    void printData() override;
};