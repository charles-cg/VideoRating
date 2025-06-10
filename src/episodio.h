#pragma once
#include "video.h"

class Episodio : public Video {
private:
    string nombreEpisodio;
    int numeroTemporada;
public:
    Episodio();
    ~Episodio();
    
    void setNumeroEpisodio(string newNombreEpisodio);
    void setNumeroTemporada(int newNumeroTemporada);
    void printData() override;
};