#include <iostream>
#include "datos.h"
#include "menu.h"
#include "episodio.h"
#include "pelicula.h"

int main() {
    Datos data;
    Menu menuMain;

    menuMain.generarMenu();
    menuMain.seleccionarOpcion(data);

    return 0;
}