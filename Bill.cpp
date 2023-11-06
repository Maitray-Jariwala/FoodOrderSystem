#include "Bill.h"
#include "Menu.h"
#include <iomanip>

Bill::Bill()
{
    price = 0;
}
void Bill::printBill(ForOrder::Order *order, int totalOrders)
{
    double totalBill = 0.0;

    cout << "------YOUR BILL HERE------\n";

    for (int i = 0; i < totalOrders; i++)
    {
        int inum = order[i].itemNumber;
        int iquan = order[i].quantity;

        if (inum >= 0 && inum < 10)
        {
            cout << "Your Token Number: " << order[i].token << "\n";
            cout << Menu::Details[inum].foodItem << ", Cost: " << Menu::Details[inum].itemprice << "\n";
            cout << fixed << setprecision(2);
            cout << "Quantity Ordered: " << iquan << "\n";
            double price = Menu::Details[inum].itemprice * iquan;
            cout << "Price For Order No. " << i + 1 << ": " << price << "\n";
            totalBill += price;
        }
    }

    cout << "--------------------------\n";
    cout << "Total Bill: " << totalBill << "\n";
}
