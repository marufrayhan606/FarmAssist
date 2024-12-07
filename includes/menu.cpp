#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t  __        __   _                            _          _____                       _            _     _   " << endl;
    cout << "\t  \\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___   |  ___|_ _ _ __ _ __ ___    / \\   ___ ___(_)___| |_ " << endl;
    cout << "\t   \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | |_ / _` | '__| '_ ` _ \\  / _ \\ / __/ __| / __| __| " << endl;
    cout << "\t    \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | |  _| (_| | |  | | | | | |/ ___ \\\\__ \\__ \\ \\__ \\ |_ " << endl;
    cout << "\t     \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  |_|  \\__,_|_|  |_| |_| |_/_/   \\_\\___/___/_|___/\\__| " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t\t\t------------------------------------------------" << endl;
    cout << "\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t|              1. User Register                |" << endl;
    cout << "\t\t\t\t|              2. User Login                   |" << endl;
    cout << "\t\t\t\t|              3. Continue as Guest            |" << endl;
    cout << "\t\t\t\t|              4. Admin                        |" << endl;
    cout << "\t\t\t\t|              5. Exit                         |" << endl;
    cout << "\t\t\t\t|                                              |" << endl;
    cout << "\t\t\t\t------------------------------------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    cout << endl;

    int choice;
    bool loggedIn = false;

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
            loggedIn = loginUser();
            if (loggedIn)
            {
                loggedInLayout();
                break;
            }
            else
            {
                cout << "Login failed. Please try again." << endl;
                getchar();
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t _   _                  ____            _     _             _   _             " << endl;
    cout << "\t\t| | | |___  ___ _ __   |  _ \\ ___  __ _(_)___| |_ _ __ __ _| |_(_) ___  _ __  " << endl;
    cout << "\t\t| | | / __|/ _ \\ '__|  | |_) / _ \\/ _` | / __| __| '__/ _` | __| |/ _ \\| '_ \\ " << endl;
    cout << "\t\t| |_| \\__ \\  __/ |     |  _ <  __/ (_| | \\__ \\ |_| | | (_| | |_| | (_) | | | |" << endl;
    cout << "\t\t \\___/|___/\\___|_|     |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|\\__|_|\\___/|_| |_|" << endl;
    cout << "\t\t                                 |___/                                        " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    string username, password;
    cout << endl;
    cout << "\t\t\t\tEnter a username: ";
    getline(cin, username);
    cout << endl;
    cout << "\t\t\t\tEnter a password: ";
    getline(cin, password);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    ofstream file;
    file.open("users.csv", ios::app);
    file << username << "," << password << endl;
    file.close();
    cout << "\t\t\t\tUser registered successfully!" << endl;
    cout << endl;

    cout << "\t\t\t\tPress any key to continue" << endl;
    getchar();

    homeLayout();
}

bool loginUser()
{
    system("cls");
    string username, password;
    cin.ignore();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t\t\t _   _                  _                _       " << endl;
    cout << "\t\t\t\t| | | |___  ___ _ __   | |    ___   __ _(_)_ __  " << endl;
    cout << "\t\t\t\t| | | / __|/ _ \\ '__|  | |   / _ \\ / _` | | '_ \\ " << endl;
    cout << "\t\t\t\t| |_| \\__ \\  __/ |     | |__| (_) | (_| | | | | |" << endl;
    cout << "\t\t\t\t \\___/|___/\\___|_|     |_____\\___/ \\__, |_|_| |_|" << endl;
    cout << "\t\t\t\t                                 |___/          " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << endl;
    cout << "\t\t\t\t-----------------------------------------------------" << endl;
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t\t\tEnter your username: ";
    getline(cin, username);
    cout << endl;
    cout << "\t\t\t\tEnter your password: ";
    getline(cin, password);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t\t\t _                               _    ___       " << endl;
    cout << "\t\t\t\t| |    ___   __ _  __ _  ___  __| |  |_ _|_ __  " << endl;
    cout << "\t\t\t\t| |   / _ \\ / _` |/ _` |/ _ \\/ _` |   | || '_ \\ " << endl;
    cout << "\t\t\t\t| |__| (_) | (_| | (_| |  __/ (_| |   | || | | |" << endl;
    cout << "\t\t\t\t|_____\\___/ \\__, |\\__, |\\___|\\__,_|  |___|_| |_|" << endl;
    cout << "\t\t\t\t             |___/ |___/                         " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t\t\t\t---------------------------------" << endl;
    cout << "\t\t\t\t\t|      1. Farm Suggestions      |" << endl;
    cout << "\t\t\t\t\t|      2. Market                |" << endl;
    cout << "\t\t\t\t\t|      3. Logout                |" << endl;
    cout << "\t\t\t\t\t|      4. Exit                  |" << endl;
    cout << "\t\t\t\t\t---------------------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    cout << endl;
    int choice;

    do
    {
        cout << "\t\tEnter your choice: ";
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\t\t  _____                       ____                              _   _                 " << endl;
        cout << "\t\t |  ___|_ _ _ __ _ __ ___    / ___| _   _  __ _  __ _  ___  ___| |_(_) ___  _ __  ___ " << endl;
        cout << "\t\t | |_ / _` | '__| '_ ` _ \\   \\___ \\| | | |/ _` |/ _` |/ _ \\/ __| __| |/ _ \\| '_ \\/ __|" << endl;
        cout << "\t\t |  _| (_| | |  | | | | | |   ___) | |_| | (_| | (_| |  __/\\__ \\ |_| | (_) | | | \\__ \\" << endl;
        cout << "\t\t |_|  \\__,_|_|  |_| |_| |_|  |____/ \\__,_|\\__, |\\__, |\\___||___/\\__|_|\\___/|_| |_|___/" << endl;
        cout << "\t\t                                          |___/ |___/                                 " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t\t|        Enter your choice:     |" << endl;
        cout << "\t\t\t\t\t|        1. Crops               |" << endl;
        cout << "\t\t\t\t\t|        2. Livestock           |" << endl;
        cout << "\t\t\t\t\t---------------------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << endl;
        cout << "\t\tEnter your choice: ";
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t\t\t     _       _           _          _                _       " << endl;
    cout << "\t\t\t\t    / \\   __| |_ __ ___ (_)_ __    | |    ___   __ _(_)_ __  " << endl;
    cout << "\t\t\t\t   / _ \\ / _` | '_ ` _ \\| | '_ \\   | |   / _ \\ / _` | | '_ \\ " << endl;
    cout << "\t\t\t\t  / ___ \\ (_| | | | | | | | | | |  | |__| (_) | (_| | | | | |" << endl;
    cout << "\t\t\t\t /_/   \\_\\__,_|_| |_| |_|_|_| |_|  |_____\\___/ \\__, |_|_| |_|" << endl;
    cout << "\t\t\t\t                                               |___/         " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "\t\t\t\t--------------------------------------------------------------------" << endl;
    cout << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t\t\t               Enter admin username: ";
    cin >> username;
    if (username == admin.username)
    {
        cout << "\t\t\t\t               Enter admin password: ";
        cin >> password;
        cout << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        if (password == admin.password)
        {
            cout << "\t\t\t\tLogin successful" << endl;
            cout << endl;
            cout << endl;
            getchar();
            cout << "\t\t\t\tPress any key to continue" << endl;
            getchar();
            adminPanel();
        }
        else
        {
            cout << "\t\t\t\tInvalid username or password" << endl;
        }
    }
    else
    {
        cout << "\t\t\t\tInvalid username or password" << endl;
    }
}
