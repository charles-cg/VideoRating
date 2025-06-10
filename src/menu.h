#pragma once

class Menu {
private:
    int opcion;
public:
    Menu();
    void generarMenu();
    bool seleccionarOpcion();
    ~Menu();
};