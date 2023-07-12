#include <iostream>
#include <windows.h>

using namespace std;

void color(const string& text, int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    cout << text << endl;
    SetConsoleTextAttribute(hConsole, 7);
}

void intro()
{
    system("CLS");

    color("\t#### ##   ## ##    ## ##              ##     ####       ####   ### ###  ### ###           #### ##   ## ##            ### ##     ####   ### ###  ", 10);
    Sleep(50);
    color("\t# ## ##  ##   ##  ##   ##              ##     ##         ##     ##  ##   ##  ##           # ## ##  ##   ##            ##  ##     ##     ##  ##  ", 10);
    Sleep(50);
    color("\t  ##     ##   ##  ##   ##            ## ##    ##         ##     ##  ##   ##                 ##     ##   ##            ##  ##     ##     ##      ", 10);
    Sleep(50);
    color("\t  ##     ##   ##  ##   ##            ##  ##   ##         ##     ##  ##   ## ##              ##     ##   ##            ##  ##     ##     ## ##   ", 10);
    Sleep(50);
    color("\t  ##     ##   ##  ##   ##            ## ###   ##         ##     ### ##   ##                 ##     ##   ##            ##  ##     ##     ##      ", 10);
    Sleep(50);
    color("\t  ##     ##   ##  ##   ##            ##  ##   ##  ##     ##      ###     ##  ##             ##     ##   ##            ##  ##     ##     ##  ##  ", 10);
    Sleep(50);
    color("\t ####     ## ##    ## ##            ###  ##  ### ###    ####      ##    ### ###            ####     ## ##            ### ##     ####   ### ###  ", 10);
    Sleep(4500);
}

int main()
{
    intro();

    return 0;
}
