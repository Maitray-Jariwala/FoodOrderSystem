#ifndef BILL_H
#define BILL_H

#include "ForOrder.h"

class Bill
{
public:
    Bill();

    // Member function to print the bill
    void printBill(ForOrder::Order *order, int totalOrders);

private:
    int price;
};

#endif
