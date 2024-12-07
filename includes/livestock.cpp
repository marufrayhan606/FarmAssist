#include <iostream>
#include "livestock.h"
using namespace std;

double livestockArea;

void dataForLivestock()
{
    cout << "\t\t\t\tEnter the livestock area in acres: ";
    cin >> livestockArea;

}

void suggestLivestock()
{
    struct Livestock {
        string type;
        double monthlyCost;
        double feedAmount;
        double areaRequired;
    };

    Livestock livestockOptions[] = {
        {"Cattle", 150.0, 500.0, 1.5},
        {"Sheep", 50.0, 150.0, 0.5},
        {"Goats", 40.0, 120.0, 0.4},
        {"Pigs", 100.0, 300.0, 0.8},
        {"Chickens", 20.0, 50.0, 0.1}
    };
    cout << "\n\n";
    cout << "\t\t\t\tSuggested livestock options for your farm:\n\n\n";
    for (const auto& livestock : livestockOptions) {
        if (livestockArea >= livestock.areaRequired) {
            int maxLivestock = static_cast<int>(livestockArea / livestock.areaRequired);
            cout << "\t\t\t\t------------------------------------" << endl;
            cout << "\t\t\t\t  Type: " << livestock.type << endl;
            cout << "\t\t\t\t------------------------------------" << endl;
            cout << "\t\t\t\t   * Monthly Cost: $" << livestock.monthlyCost * maxLivestock << endl;
            cout << "\t\t\t\t   * Feed Amount: " << livestock.feedAmount * maxLivestock << " lbs" << endl ;
            cout << "\t\t\t\t   * Area Required: " << livestock.areaRequired * maxLivestock << " acres\n" << endl << endl;
        }
    }

    cout << "\t\tPress any key to continue...";
    cin.ignore();
    cin.get();
}
void livestock()
{
    system("cls");
    dataForLivestock();
    suggestLivestock();

}