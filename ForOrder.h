#ifndef FORORDER_H
#define FORORDER_H

class ForOrder
{
public:
    struct Order
    {
        int itemNumber;
        int quantity;
        int token;
    };

    Order order[1000];

    int totalOrders = 0;
    int ordersServed = 0;

    char orderDecision = 'N';

    int n, quan;

    void takeOrder();
};

#endif
