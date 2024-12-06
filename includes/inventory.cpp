#include "inventory.h"
using namespace std;

void viewStock() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t\t\t ____  _             _    " << endl;
    cout << "\t\t\t\t/ ___|| |_ ___   ___| | __" << endl;
    cout << "\t\t\t\t\\___ \\| __/ _ \\ / __| |/ /" << endl;
    cout << "\t\t\t\t ___) | || (_) | (__|   < " << endl;
    cout << "\t\t\t\t|____/ \\__\\___/ \\___|_|\\_\\" << endl;
    cout << "\t\t\t\t                           " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    vector<Crop> crops = loadInventory();
    cout << "\033[31m" << "\t\t\t\t" << left << setw(20) << "Name" << setw(10) << "Stock" << setw(15) << "Price per Unit" << "\033[0m" << endl;
    cout << "\t\t\t\t" << "---------------------------------------------------" << endl;
    for (const auto& crop : crops) {
        cout << "\t\t\t\t" << left << setw(20) << crop.name << setw(10) << crop.stock << setw(15) << crop.pricePerUnit << endl;
    }
    cout << "\t\t\t\t" << "---------------------------------------------------" << endl;
}

vector<Crop> loadInventory() {
    vector<Crop> crops;
    ifstream file("inventory.csv");
    if (!file.is_open()) {
        cout << "Error opening inventory file." << endl;
        return crops;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Crop crop;
        string stockStr, priceStr;

        getline(ss, crop.name, ',');
        getline(ss, stockStr, ',');
        getline(ss, priceStr, '\n');

        crop.stock = stoi(stockStr);
        crop.pricePerUnit = stod(priceStr);

        crops.push_back(crop);
    }
    file.close();
    return crops;
}