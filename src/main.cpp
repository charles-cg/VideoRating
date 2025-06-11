#include <iostream>
#include "datos.h"
#include "menu.h"
#include "episodio.h"
#include "pelicula.h"

int main() {
    Datos data;
    Menu menuMain;

    Datos *dataPtr = &data;


    bool flagMenu = true;

    while (flagMenu) {
        menuMain.generarMenu();
        flagMenu = menuMain.seleccionarOpcion(dataPtr);
    }

    return 0;
}