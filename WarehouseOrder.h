#pragma once
#include <iostream>
#include "Order.h"

class WarehouseOrder : public Order {
public:
    WarehouseOrder(std::vector<std::pair<Item*, int>> store_order) {
        _order_list = store_order;
    }
    WarehouseOrder() { _order_list.resize(0); }

};