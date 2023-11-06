#include "ForOrder.h"
#include "Bill.h"
#include <iostream>
#include <string>

using namespace std;

void ForOrder::takeOrder()
{
    while (totalOrders < 1000)
    {
        std::cout << "Please Enter Your Item Number from the Menu : ";
        std::cin >> n;

        std::cout << "Please Enter Quantity Of Your Item : ";
        std::cin >> quan;

        order[totalOrders].itemNumber = n - 1;
        order[totalOrders].quantity = quan;
        order[totalOrders].token = totalOrders + 1;

        totalOrders++;

        std::cout << "Would You Like to Order Another Item? ";
        std::cout << "Enter Y if you would like to ";
        std::cin >> orderDecision;
        if (orderDecision == 'N' || orderDecision == 'n')
        {
            // If the user doesn't want to order more, print the bill
            Bill bill;
            bill.printBill(order, totalOrders);
            break;
        }
    }
}
