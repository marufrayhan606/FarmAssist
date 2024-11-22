#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "guest.h"
#include "crops.h"
#include "livestock.h"
#include "marketPlace.h"
#include "admin.h"

using namespace std;

void homeLayout()
{
    system("cls");

    cout << "Welcome to FarmAssist" << endl;
    cout << "---------------------------------" << endl;
    cout << endl;
    cout << "\tPlease select an option" << endl;
    cout << "\t1. User Register" << endl;
    cout << "\t2. User Login" << endl;
    cout << "\t3. Continue as Guest" << endl;
    cout << "\t4. Admin" << endl;
    cout << "\t5. Exit" << endl;
    cout << endl;

    int choice;

    do
    {
        cout << "\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:

            if (loginUser())
            {
                loggedInLayout();
                break;
            }
            else
            {
                cout << "Login failed. Please try again." << endl;
                loginUser();
            }
            break;
        case 3:
            guest();
            break;
        case 4:
            admin();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice. Please try again" << endl;
            break;
        }

    } while (true);
}

void registerUser()
{
    system("cls");
    cin.ignore();

    cout << "User Registration" << endl;
    cout << "---------------------------------" << endl;
    cout << endl;

    string username, password;
    cout << "Enter a username: ";
    getline(cin, username);
    cout << "Enter a password: ";
    getline(cin, password);

    ofstream file;
    file.open("users.csv", ios::app);
    file << username << "," << password << endl;
    file.close();
    system("cls");
    cout << "User registered successfully!" << endl;
    homeLayout();
}

bool loginUser()
{
    system("cls");
    string username, password;
    cin.ignore();

    cout << "User Login" << endl;
    cout << "---------------------------------" << endl;
    cout << endl;

    cout << "Enter your username: ";
    getline(cin, username);
    cout << endl;
    cout << "Enter your password: ";
    getline(cin, password);

    ifstream file;
    file.open("users.csv");
    string storedUsername, storedPassword;
    while (getline(file, storedUsername, ',') && getline(file, storedPassword, '\n'))
    {
        if (storedUsername == username && storedPassword == password)
        {
            return true;
        }
    }
    return false;
}

void loggedInLayout()
{
    system("cls");
    cout << "Logged In" << endl;
    cout << "---------------------------------" << endl;
    cout << endl;
    
    cout << "Please select an option" << endl;
    cout << "1. Farm Suggestions" << endl;
    cout << "2. Market" << endl;
    cout << "3. Logout" << endl;
    cout << "4. Exit" << endl;

    int choice;

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            farmSuggestion();
            break;
        case 2:
            market();
            break;
        case 3:
            homeLayout();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again" << endl;
            break;
        }

    } while (true);
}

void farmSuggestion()
{
    int choice;
    do
    {
        system("cls");

        cout << "Farm Suggestions" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
        
        cout << "Enter your choice:" << endl; 
        cout << "1. Crops" << endl;
        cout << "2. Livestock" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            crops();
            break;
        case 2:
            livestock();
            break;
        default:
            cout << "Invalid choice. Please try again" << endl;
            break;
        }

    } while (true);
}

void admin()
{
    struct Admin
    {
        const string username = "admin";
        const string password = "admin";
    };

    Admin admin;
    string username, password;

    system("cls");

    cout << "Admin Login" << endl;
    cout << "---------------------------------" << endl;
    cout << endl;

    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;
    if (username == admin.username && password == admin.password)
    {
        adminPanel();
    }
    else
    {
        cout << "Invalid username or password" << endl;
    }
    
}
