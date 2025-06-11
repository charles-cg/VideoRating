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
            int optGeneroCalificacion;

            std::cout << "Eliga que desea buscar en el catálogo\n1. Genero\n2. Calificacion\nOpcion: ";

            std::cin >> optGeneroCalificacion;

            if (optGeneroCalificacion == 1) {
                string searchGenero;
            
                newData->displayDatos();

                std::cout << "Por favor ingrese el genero a buscar" << std::endl;
                std::cin >> searchGenero;
            
                if(newData->buscarVideosGeneral(searchGenero)) {
                    return true;
                } else {
                    std::cout << "No hubo videos con genero "<< searchGenero << std::endl;
                    return true;
                }
            } else if (optGeneroCalificacion == 2) {
                float searchCalificacion;
            
                newData->displayDatos();

                std::cout << "Por favor ingrese la calificacion a buscar del 1-5" << std::endl;
                std::cin >> searchCalificacion;
            
                if (searchCalificacion < 1 || searchCalificacion > 5) {
                    std::cout << "La calificacion debe estar entre 1 y 5" << std::endl;
                    return true;
                } else {
                    if(newData->buscarVideosGeneral(searchCalificacion)) {
                        return true;
                    } else {
                        std::cout << "No hubo videos con calificacion "<< searchCalificacion << std::endl;
                            return true;
                    }
                } 
            } else {
                std::cout << "Opción invalida\n";
                return true;
            }
        }

        case 4: {
            string searchNombre;
            float searchCalificacion;
            
            newData->displayDatos();

            std::cout << "\nIngrese el Nombre de la serie a buscar: " << std::endl;
            std::cin >> searchNombre;


            std::cout << "Por favor ingrese la calificacion a buscar del 1-5" << std::endl;
            std::cin >> searchCalificacion;
            
            if (searchCalificacion < 1 || searchCalificacion > 5) {
                std::cout << "La calificacion debe estar entre 1 y 5" << std::endl;
                return true;
            } else {
                if(newData->buscarEpisodios(searchNombre, searchCalificacion)) {
                    return true;
                } else {
                        std::cout << "No hubo episodios de la serie "<< searchNombre <<" con calificacion "<< searchCalificacion << std::endl;
                        return true;
                }
            }    
        }

        case 5: {
            float searchCalificacion;
            
            newData->displayDatos();

            std::cout << "Por favor ingrese la calificacion a buscar del 1-5" << std::endl;
            std::cin >> searchCalificacion;
            
            if (searchCalificacion < 1 || searchCalificacion > 5) {
                std::cout << "La calificacion debe estar entre 1 y 5" << std::endl;
                return true;
            } else {
                if(newData->buscarPeliculas(searchCalificacion)) {
                    return true;
                } else {
                        std::cout << "No hubo peliculas con calificacion"<< searchCalificacion << std::endl;
                        return true;
                }
            } 
        }
        
        case 6: {
            int calificacion;
            std::string idEpisodio;
            
            newData->displayDatos();

            std::cout << "\nIngrese el ID del video a calificar: " << std::endl;
            std::cin >> idEpisodio;


            std::cout << "Por favor ingrese su calificación del 1-5" << std::endl;
            std::cin >> calificacion;
            

            if (calificacion < 1 || calificacion > 5) {
                std::cout << "La calificación debe estar entre 1 y 5" << std::endl;
                return true;
            } else {
                if(newData->calificarVideo(idEpisodio, calificacion)) {
                    std::cout << "Se asignó la calificación" << std::endl;
                    return true;
                } else {
                        std::cout << "No se pudo asignar la calificacion"<< std::endl;
                        return true;
                }
            }      
            return true;
        }

        case 0:
            std::cout << "Saliendo del programa...\n";
            return false;
        default:
            std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
            return true;
    }
}