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
    
    // getchar();

    homeLayout();

    return 0;
}