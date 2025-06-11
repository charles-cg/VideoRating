#pragma once
#include "datos.h"

class Menu {
private:
    int opcion;
public:
    Menu();
    void generarMenu();
    bool seleccionarOpcion(Datos newData);
    ~Menu();
};