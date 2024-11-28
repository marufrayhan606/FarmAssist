#include <iostream>
#include <windows.h>
#include "includes/menu.h"
using namespace std;

void printSlowly(const std::string& s, int delay)
{
    for (char c : s)
    {
        Sleep(delay);
        putchar(c);
        fflush(stdout);
    }
}

int main()
{
    system("cls");

    
    cout << endl;
    cout << endl;
    printSlowly("\t\t\t _      __    __                     __     \n", 1);
    printSlowly("\t\t\t| | /| / /__ / /______  __ _  ___   / /____ \n", 1);
    printSlowly("\t\t\t| |/ |/ / -_) / __/ _ \\/  ' \\/ -_) / __/ _ \\\n", 1);
    printSlowly("\t\t\t|__/|__/\\__/_/\\__/\\___/_/_/_/\\__/  \\__/\\___/\n", 1);
    printSlowly("\t\t\t                                             \n", 1);
    printSlowly("\t\t\t\t\t\t ______                                    _     _   \n", 3);
    printSlowly("\t\t\t\t\t\t|  ____|                     /\\           (_)   | |  \n", 3);
    printSlowly("\t\t\t\t\t\t| |__ __ _ _ __ _ __ ___    /  \\   ___ ___ _ ___| |_ \n", 3);
    printSlowly("\t\t\t\t\t\t|  __/ _` | '__| '_ ` _ \\  / /\\ \\ / __/ __| / __| __|\n", 3);
    printSlowly("\t\t\t\t\t\t| | | (_| | |  | | | | | |/ ____ \\\\__ \\__ \\ \\__ \\ |_ \n", 3);
    printSlowly("\t\t\t\t\t\t|_|  \\__,_|_|  |_| |_| |_/_/    \\_\\___/___/_|___/\\__|\n", 3);
    cout << endl;
    cout << endl;
    printSlowly("\t\t\t\t\t\tLoading ... \n", 3);
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printSlowly("                                                                                                        \n", 3);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    
    // getchar();

    homeLayout();

    return 0;
}