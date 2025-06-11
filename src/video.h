#pragma once
#include <string>
#define VIDEO_ATTRIB_SIZE 5

using std::string;

class Video {
private:
    string id;
    string nombre;
    int duracion;
    string genero;
    float calificacion;
    int sumaCalificacion;
    int numeroCalificaciones;
public:
    Video();
    ~Video();

    void setId(string newId);
    void setNombre(string newNombre);
    void setDuracion(int newDuracion);
    void setGenero(string newGenero);
    void setCalificacion(float newCalificacion);

    string getId();
    string getNombre();
    int getDuracion();
    string getGenero();
    float getCalificacion();
    
    virtual void printData();
};