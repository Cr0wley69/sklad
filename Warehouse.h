#pragma once
#include<iostream>
#include<vector>
#include"SFML/Graphics.hpp"
#include "Shelf.h"
class Warehouse {
public:
    Warehouse(int shelf_size = 10) {
        for (int i = 0; i < shelf_size; ++i) {
            _shelfs.push_back(new Shelf(15));
        }
    }

    void setShelfSize(int val) {
        for (int i = 0; i < val; ++i) {
            _shelfs.push_back(new Shelf(15));
        }
    }
    void addItem(Item* item, int val) {
        for (auto i : _shelfs) {
            if (val > 0) {
                val -= i->addNewItem(item, val);
            }
        }
    }

    void updateItems() {
        for (auto &i : _shelfs) {
            std::vector<std::pair<Item*, int>> items = i->getItem();
            for (auto &j : items) {
                j.first->setShelfLife(j.first->getShelfLife() - 1);
            }
        }
    }

    void removeItem(Item* item, int val) {
        bool cover = false;
        for (auto i : _shelfs) {
            if (i->getColItem(item) > 0) {
                cover = true;
            }
        }
        if (!cover)
            return;
        for (auto i : _shelfs) {
            if (val > 0) {
                val -= i->removeItem(item, val);
            }
        }
    }

    std::vector<std::pair<Item*, int>> getDelayItem(int val = 5) {
        std::vector<std::pair<Item*, int>> items;
        for (auto i : _shelfs) {
            for (auto j : i->getItem()) {
                if(j.first->getShelfLife() < val)
                   items.push_back(j);
            }
        }
        return items;
    }

    int getColItem(std::wstring name){
       int cnt = 0;
       for (auto i : _shelfs) {
           for (auto j : i->getItem()) {
               if (j.first->getShelfLife() > 0)
                   ++cnt;
           }
       }
       return cnt;
    }
    Shelf* getShelf(int val) {
        return _shelfs[val];
    }

    std::vector<Shelf*> getShelfs() {
        return _shelfs;
    }

    int getWareHouseSize() {
        return _shelfs.size();
    }

private:

    std::vector<std::wstring> _list_of_items;
    std::vector<Shelf*> _shelfs;
};

