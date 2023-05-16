#include <iostream>
#include <conio.h> // funkcje getch i kbhit
using namespace std;
int main()
{
    int x = 0, y = 1;
    while (1)
    {
          if (kbhit()) // kbhit - sprawdza czy jest cos w buforze klawiatury jak jest to zwaraca 1, jak nie to 0
          {
              x = getch(); // tu musi byc getch!!!
              break;
          }
    }
    cout << "x = " << x << endl;
    if (x == 49) cout << "wcisnieto " << 1 << endl; // kod klawisza 1 to 49 a klawisza 2 to 50
    else if (x == 50)cout << "wcisnieto " << 2 << endl;
    system("PAUSE");
    return 0;
}
