#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    const int w = 20;
    int i, l[20] = {0}, suma = 0;
    char r[w];
    cin >> r;
    for (i = 0; r[i]; i++)
    {
        if ( r[i] == 'I') l[i] = 1;
        else if ( r[i] == 'V') l[i] = 5;
        else if ( r[i] == 'X') l[i] = 10;
        else if ( r[i] == 'L') l[i] = 50;
        else if ( r[i] == 'C') l[i] = 100;
        else if ( r[i] == 'D') l[i] = 500;
        else if ( r[i] == 'M') l[i] = 1000;
    }
    for (i = 0; i < w; i++)
    {
        if (l[i+1] != 0 and l[i+1] > l[i]) l[i] = -l[i];
        suma += l[i];
    }
    cout << suma << endl;
    getch();
    return 0;
}
