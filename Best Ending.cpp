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

void bestEnding(){

system("CLS");
    color ("\t\t\t##  ##    ## ##   ##  ###            ## ##   ##  ###  ### ##   ### ###  ### ##            #### ##  ###  ##  ### ###  ", 9);
    Sleep(50);
    color ("\t\t\t##  ##   ##   ##  ##   ##           ##   ##  ##   ##   ##  ##   ##  ##   ##  ##           # ## ##   ##  ##   ##  ##  ", 9);
    Sleep(50);
    color ("\t\t\t##  ##   ##   ##  ##   ##           ##       ##   ##   ##  ##   ##       ##  ##             ##      ##  ##   ##      ", 9);
    Sleep(50);
    color ("\t\t\t ## ##   ##   ##  ##   ##           ##       ##   ##   ## ##    ## ##    ##  ##             ##      ## ###   ## ##   ", 9);
    Sleep(50);
    color ("\t\t\t  ##     ##   ##  ##   ##           ##       ##   ##   ## ##    ##       ##  ##             ##      ##  ##   ##      ", 9);
    Sleep(50);
    color ("\t\t\t  ##     ##   ##  ##   ##           ##   ##  ##   ##   ##  ##   ##  ##   ##  ##             ##      ##  ##   ##  ##  ", 9);
    Sleep(50);
    color ("\t\t\t  ##      ## ##    ## ##             ## ##    ## ##   #### ##  ### ###  ### ##             ####    ###  ##  ### ###  ", 9);
    Sleep(50);
    cout << endl;
    Sleep(50);
    color ("\t### ##    ## ##   ##   ##  ### ##     ####   ### ###             ####   ###  ##  ### ###  ### ###   ## ##   #### ##    ####    ## ##   ###  ##  ", 9);
    Sleep(50);
    color ("\t##  ##   ##   ##   ## ##    ##  ##     ##     ##  ##              ##      ## ##   ##  ##   ##  ##  ##   ##  # ## ##     ##    ##   ##    ## ##  ", 9);
    Sleep(50);
    color ("\t   ##    ##   ##  # ### #   ##  ##     ##     ##                  ##     # ## #   ##       ##      ##         ##        ##    ##   ##   # ## #  ", 9);
    Sleep(50);
    color ("\t  ##     ##   ##  ## # ##   ## ##      ##     ## ##               ##     ## ##    ## ##    ## ##   ##         ##        ##    ##   ##   ## ##   ", 9);
    Sleep(50);
    color ("\t ##      ##   ##  ##   ##   ##  ##     ##     ##                  ##     ##  ##   ##       ##      ##         ##        ##    ##   ##   ##  ##  ", 9);
    Sleep(50);
    color ("\t##  ##   ##   ##  ##   ##   ##  ##     ##     ##  ##              ##     ##  ##   ##       ##  ##  ##   ##    ##        ##    ##   ##   ##  ##  ", 9);
    Sleep(50);
    color ("\t# ####    ## ##   ##   ##  ### ##     ####   ### ###             ####   ###  ##  ####     ### ###   ## ##    ####      ####    ## ##   ###  ##  ", 9);
    Sleep(4500);
}

int main()
{
    bestEnding();

    return 0;
}
