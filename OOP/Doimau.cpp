#include <windows.h>
#include <iostream>
//setColor
using namespace std;
int main() {
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int k=1;k<=3;k++) {
        SetConsoleTextAttribute(hConsoleColor, k);
        cout << k << " - Change color!  ";
    }
    
    return 0;
}
