#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>

using namespace std;

class Menu
{
public:
    struct ItemDetails
    {
        string foodItem;
        float itemprice;
    };

    static ItemDetails Details[10];

    Menu();

    void displayMenu();
};

#endif

