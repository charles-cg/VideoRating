#include <iostream>
#include "menu.h"


Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::generarMenu() {
    std::cout << "\nMenu:\n1. Cargar archivo de datos\n2. Mostrar todos los datos\n";
    std::cout << "3. Mostrar los video en general con una cierta calificacion o un cierto genero\n";
    std::cout << "4. Mostrar los episodios de una determinada serie con una calificacion determinada\n";
    std::cout << "5. Mostrar las peliculas con cierta calificacion\n";
    std::cout << "6. Calificar un video\n";
    std::cout << "0. Salir\n";
}

bool Menu::seleccionarOpcion(Datos *newData) {
    std::cout << "Elige una opcion: "; //checar si es mejor input en el main o en la función
    std::cin >> opcion;

    switch (opcion) {
        case 1:
            if (!newData->cargarDatos()) {
                std::cout << "Ocurrio un error al cargar los datos\nCerrando el programa..." << std::endl;
                return false;
            }
            std::cout << "Se cargaron los archivos correctamente" << std::endl;
            return true;
        case 2:
            newData->displayDatos();
            return true;
        case 3:

            return true;
        case 4:

            return true;
        case 5:

            return true;
        case 6:

            return true;
        case 0:

            return false;
        default:
            std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
            return true;
    }
}