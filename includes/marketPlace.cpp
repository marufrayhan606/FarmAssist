#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <algorithm>
#include "marketPlace.h"
#include "inventory.h"
#include "menu.h"

using namespace std;

vector<CartItem> cart;

void market() {
    system("cls");
    cout << "Market Place" << endl;
    cout << "---------------------------------" << endl;
    vector<Crop> crops = loadInventory();
    viewStock();

    int choice;
    do {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t|        1. Add to Cart         |" << endl;
        cout << "\t\t\t\t|        2. View Cart           |" << endl;
        cout << "\t\t\t\t|        3. Place Order         |" << endl;
        cout << "\t\t\t\t|        4. Home                |" << endl;
        cout << "\t\t\t\t|        5. Exit                |" << endl;
        cout << "\t\t\t\t---------------------------------" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string cropName;
            int quantity;
            cout << "Enter crop name to add to cart: ";
            cin >> cropName;
            cout << "Enter quantity: ";
            cin >> quantity;

            auto it = find_if(crops.begin(), crops.end(), [&cropName](const Crop& crop) {
                return crop.name == cropName;
            });

            if (it != crops.end() && it->stock >= quantity) {
                addToCart(*it, quantity);
                cout << "Added to cart successfully!" << endl;
            } else {
                cout << "Crop not found or insufficient stock." << endl;
            }
            break;
        }
        case 2:
            viewCart();
            break;
        case 3:
            placeOrder();
            break;
        case 4:
            loggedInLayout();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (true);
}
void addToCart(const Crop& crop, int quantity) {
    for (auto& item : cart) {
        if (item.crop.name == crop.name) {
            item.quantity += quantity;
            return;
        }
    }
    cart.push_back({crop, quantity});
}

void viewCart() {
    if (cart.empty()) {
        cout << "Your cart is empty." << endl;
        return;
    }

    double total = 0.0;
    cout << "\033[31m" << left << setw(20) << "Name" << setw(10) << "Quantity" << setw(15) << "Price per unit" << setw(15) << "Subtotal" << "\033[0m" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (const auto& item : cart) {
        double subtotal = item.quantity * item.crop.pricePerUnit;
        total += subtotal;
        cout << left << setw(20) << item.crop.name << setw(10) << item.quantity << setw(15) << item.crop.pricePerUnit << setw(15) << subtotal << endl;
    }
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Total: " << total << " tk" << endl;
    cout << endl;
}

void placeOrder() {
    if (cart.empty()) {
        cout << "Your cart is empty. Add items before placing the order." << endl;
        return;
    }

    vector<Crop> crops = loadInventory();
    for (const auto& item : cart) {
        for (auto& crop : crops) {
            if (crop.name == item.crop.name) {
                crop.stock -= item.quantity;
            }
        }
    }

    ofstream file("inventory.csv");
    if (!file.is_open()) {
        cout << "Error opening inventory file for writing." << endl;
        return;
    }

    for (const auto& crop : crops) {
        file << crop.name << "," << crop.stock << "," << crop.pricePerUnit << endl;
    }
    file.close();

    cout << "Order placed successfully!" << endl;
    cart.clear();
    getchar();
    loggedInLayout();
}


