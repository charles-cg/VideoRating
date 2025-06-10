#pragma once

class Menu {
private:
    int option;
public:
    Menu();
    void displayMenu();
    bool selectOption();
    ~Menu();
};