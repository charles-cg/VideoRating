#pragma once
#include <string>

using std::string;

class Video {
private:
    string id;
    string nombre;
    float duracion;
    string genero;
    float calificacion;
public:
    Video();
    ~Video();

    void setId(string newId);
    void setNombre(string newNombre);
    void setDuracion(float newDuracion);
    void setGenero(string newGenero);
    void setCalificacion(float newCalificacion);

    string getId();
    string getNombre();
    float getDuracion();
    string getGenero();
    float getCalificacion();
    
    virtual void printData();
};