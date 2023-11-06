#include "Menu.h"

Menu::ItemDetails Menu::Details[10];

Menu::Menu()
{

    Details[0] = {"1. Seven Cheesy Pizza", 250};
    Details[1] = {"2. Paneer Tikka Pizza", 250};
    Details[2] = {"3. Basil & Pesto", 250};
    Details[3] = {"4. Burn To Hell", 250};
    Details[4] = {"5. Cheese Burst", 250};
    Details[5] = {"6. Hawaiian Fantasy", 250};
    Details[6] = {"7. African BBQ", 250};
    Details[7] = {"8. Classic Margherita", 250};
    Details[8] = {"9. Char Grilled", 250};
    Details[9] = {"10. Mushroom Riot", 250};
}

void Menu::displayMenu()
{
    // Printing the menu
    for (int i = 0; i < 10; i++)
    {
        std::cout << Details[i].foodItem << " Price: " << Details[i].itemprice << "\\-\n";
    }
}
