#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>

using namespace std;



struct Crop {
    string name;
    int stock;
    double pricePerUnit;
};

struct CartItem {
    Crop crop;
    int quantity;
};


vector<Crop> loadInventory();
void viewStock();


#endif // INVENTORY_H
