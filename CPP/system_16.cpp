#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    long long int n, reszta[30] = {0};
    int i = 0;
    cin >> n;
    while (n > 0)
    {
          reszta[i] = n%16;
          n = (n-(n%16))/16;
          i++;
    }
    for (i--; i >= 0; i--)
    {
        switch (reszta[i])
        {
            case 10: cout << "A"; break;
            case 11: cout << "B"; break;
            case 12: cout << "C"; break;
            case 13: cout << "D"; break;
            case 14: cout << "E"; break;
            case 15: cout << "F"; break;
            default: cout << reszta[i]; 
        }        
    }
    cout << endl;
    getch();
    return 0;
}
