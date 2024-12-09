#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
#include "admin.h"
#include "menu.h"

using namespace std;

void saveInventory(const vector<Crop> &crops)
{
    ofstream file("inventory.csv");
    if (!file.is_open())
    {
        cout << "Error opening inventory file for writing." << endl;
        return;
    }

    for (const auto &crop : crops)
    {
        file << crop.name << "," << crop.stock << "," << crop.pricePerUnit << endl;
    }
    file.close();
}

void manageStock()
{
    int choice;
    vector<Crop> crops = loadInventory();
    string cropName, cropStock, cropPrice;
    cout << "Enter the crop name to update: ";
    cin.ignore();
    getline(cin, cropName);

    bool found = false;
    for (auto &crop : crops)
    {
        if (crop.name == cropName)
        {
            cout << "Enter new stock quantity: ";
            cin >> crop.stock;
            cout << "Enter new price per unit: ";
            cin >> crop.pricePerUnit;
            found = true;
            break;
        }
    }

    if (!found)
    {
        // cout << "Crop not found in inventory." << endl;
        cout << "Do you wish to add " << cropName << "?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << endl;
        cout << "=> ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter new stock quantity: ";
            cin >> cropStock;
            cout << "Enter new price per unit: ";
            cin >> cropPrice;
            crops.push_back(Crop{cropName, stoi(cropStock), stod(cropPrice)});
            cout << "Item added successfully." << endl;
        }
        else
        {
            cout << "Item not added. Inventory Restored" << endl;
        }
        
    }
    else
    {
        
        cout << "Inventory updated successfully." << endl;
    }
    saveInventory(crops);
}

void adminPanel()
{

    system("cls");

    int choice;
    do
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\t\t\t\t     _       _           _          ____                  _ " << endl;
        cout << "\t\t\t\t    / \\   __| |_ __ ___ (_)_ __    |  _ \\ __ _ _ __   ___| |" << endl;
        cout << "\t\t\t\t   / _ \\ / _` | '_ ` _ \\| | '_ \\   | |_) / _` | '_ \\ / _ \\ |" << endl;
        cout << "\t\t\t\t  / ___ \\ (_| | | | | | | | | | |  |  __/ (_| | | | |  __/ |" << endl;
        cout << "\t\t\t\t /_/   \\_\\__,_|_| |_| |_|_|_| |_|  |_|   \\__,_|_| |_|\\___|_|" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\t\t\t    --------------------------------------------------------------------" << endl;
        cout << "\t\t\t    |                         1. View Stock                            |" << endl;
        cout << "\t\t\t    |                         2. Manage Stock                          |" << endl;
        cout << "\t\t\t    |                         3. Logout                                |" << endl;
        cout << "\t\t\t    |                         4. Exit                                  |" << endl;
        cout << "\t\t\t    --------------------------------------------------------------------" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            viewStock();
            break;
        case 2:
            viewStock();
            manageStock();
            break;
        case 3:
            homeLayout();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (true);
}
