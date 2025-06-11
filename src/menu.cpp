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
        case 3: {
            float searchCalificacion;
            int searchId;

            newData->displayDatos();
            std::cout << "\nIngrese el ID de la pelicula a buscar: " << std::endl;
            std::cin >> searchId;
            std::cout << "Por favor ingrese la calificacion a buscar del 1-5" << std::endl;
            std::cin >> searchCalificacion;
            if (searchCalificacion < 1 || searchCalificacion > 5) {
                std::cout << "La calificacion debe estar entre 1 y 5" << std::endl;
                return true;
            } else {
                if(newData->buscarPeliculas(searchId, searchCalificacion)) {
                    return true;
                } else {
                    std::cout << "No hubo peliculas con calificacion "<< searchCalificacion << std::endl;
                    return true;
                }
                return true;
            }
            return true;
        }
        case 4:

            return true;
        case 5: {
            int cali;
            std::cout << "Por favor, ingrese una opcion: " << std::endl;
            std::cin >> cali;

            switch (cali) {
                case 1:
                    newData->displayDatos(1);
                case 2:
                    newData->displayDatos(2);
                case 3:
                    newData->displayDatos(3);
                case 4:
                    newData->displayDatos(4);
                case 5:
                    newData->displayDatos(5);
                default:
                    std::cout << "Opción invalida, por favor intente de nuevo" << std::endl;
            }
        }

            return true;
        case 6:
            int calificacion;
            int eleccion;
            string idEpisodio;
            std::cout << "¿Que quiere calificar?\n" << std::endl;
            std::cout << "1. Serie\n2. Pelicula\n";
            std::cin >> eleccion;
            if(eleccion == 1) {
                newData->displayDatos();

                std::cout << "Ingrese el ID del video a calificar: " << std::endl;
                std::cin >> idEpisodio;

                std::cout << "Por favor ingrese su calificación del 1-5" << std::endl;
                std::cin >> calificacion;

                if (calificacion < 1 || calificacion > 5) {
                    std::cout << "La calificación debe estar enyre 1 y 5" << std::endl;
                } else {
                    if(newData->calificarEpisodio(idEpisodio, calificacion)) {
                        std::cout << "Se asignó la calificación" << std::endl;
                    } else {
                        std::cout << "No se pudo asignar la calificacion"<< std::endl;
                    }
                }
            }

            return true;
        case 0:

            return false;
        default:
            std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
            return true;
    }
}